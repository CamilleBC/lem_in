/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 10:52:38 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/25 13:09:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "error_manager.h"
#include "utilities.h"

/* Logic:
**
** WARNING: cette technique risque de prendre un temps extremement long si
** les chemins possibles sont nombreux. Peut etre prevoir un nombre de recursions
** maximum ?
**
** Dans cet exemple il y a trois chemins max. Sinon on lance une recursive par
** chemin max possible.
**
** On fait un tableau en 2d.
** way[0] => meilleur chemin pour 1 seul chemin
** way[1] => tableau des 2 meilleur chemins possibles qui fonctionnent ensemble
** way[2] => tableau des 3 meilleur chemins possibles qui fonctionnent ensemble
**
** On lance la recursive pour recuperer le meilleur chemin. Si on ne trouve pas,
** la carte est fausse, on imprime 'error'.
**
** Si on trouve le chemin le plus rapide, on revient dans la fonction principale
** On copie le chemin le plus rapide dans l'index way[1][0] et on lance la
** recursive pour trouver un autre chemin vers END.
** Si on trouve c'est cool, sinon on backtrack sur le premier way et on relance
** la recursive. Ainsi de suite. Si on ne trouve rien alors le seul chemin
** possible est celui sauvegarde dans l'index way[0].
**
** On procede de meme
**
** CE QUI SUIT EST OBSOLETE UN EXEMPLE DE CE QUI POURRAIT SE PASSER DANS LE
** BACKTRACK
**
** F1:
** On a deja le chemin le plus court dans way[1][0]
** F2:
** On lance rec 2 et on sauve dans way[1][1].
**
** Si F2 retourne FALSE, on relance F1 avec une copie de WA-1 appelee WA-2.
** WA-2 est une copie de WA-1 avec ces differences:
**	- tant que les rooms ont un seul link, on revient en arriere.
**	- Des qu'on trouve une room avec plus d'un link, on set way a cette piece.
**	- La room next reste visited, tout le reste de WA-1 est libere (visited=0).
**
** On trouve le chemin le plus court pour F1. Si il est bon, on cherche un
** chemin de longueur identique, et on incremente si on ne trouve pas.
**
*/

/*
** To be able to find multiple ways in case of too many ants
** and multiple ways, we need to manage the flow in our graph.
**
** 1- find an augmenting path
** 2- compute the bottleneck capacity
** 3- augment each edge and the total flow
**
**
** 1- find an augmenting path
**	Edges for the augmenting path:
**		a- Non-visited forward edge
**		b- Non-empty backward edge
**	We first find the shortest path. And fill the capacity of the edge
*/



t_way	**init_2darray(int64_t nb_ways)
{
	t_way	***ways;
	int64_t	i;

	if (!(ways = ft_memalloc(sizeof(t_way **) * nb_ways)))
		return (NULL);
	i = 0;
	while (i < ways)
		if (!(ways[i] = ft_memalloc(sizeof(t_way *) * (i + 1))))
			return (error_flow_control(nb_ways, ways));
	return (ways);
}

/*
** Logic:
**	1- We find the shortest way possible, way 1
**	2- We launch the algorithm to find a way 2 and check if we encounter a visited
**		room on the next pointer for any room on the bfs.
**	3- If it is the only way possible and it is visited, we free the way 1 and
**		continue our search on way 2.
**	4- we save way 2 and relaunch way 1 before the intersection.
**	5- If we are able to finish way 1, we check if depending on the number of
**		ants and the lenghts of the ways, it is worth saving them.
**	6- If it is, we save the ways, and launch the bfs again, etc.
*/

t_way	***find_da_wae(const t_map *map)
{
	t_way	***ways;
	int64_t	collision;
	size_t	way;
	size_t	way_array;

	ft_print("nb ways=%u\n", map->ways);
	if (!(ways = init_2darray(map->ways)))
		return (NULL);
	way_array = 0;
	while (way < map->ways)
	{
		// ETAPE 1: On copie les chemins precedents dans le tableau (pas besoin
		// de tout recalculer)
		way = 0;
		while (way < way_array)
		{
			if (!(ways[way_array][way] = dup_way(ways[way_array - 1][way])))
				return (error_flow_control(map->ways, ways));
			++way;
		}
		if (!(ways[way_array][way] = ft_memalloc(sizeof(t_way))))
			return (error_flow_control(map->ways, ways));
		//ETAPE 2: On cherche a trouver le nouveau chemin
		// Si on ne trouve pas, on revient en arriere, jusqua trouver un truc
		// qui passe
		//boucle a rajouter pour tourner jusqu'a avoir le chemin X
		ways[way_array][way]->room = get_start_room(map);
		if ((collision = breadth_first_search(map, ways[way_array][way], )) && way > 0)
		{
			// on free le precedent et on reprend depuis la collision
			--way;
			free_way(ways[way_array][way]);
			ways[way_array][way]->room = get_start_room(map);
		}
		if (!(ways[way_array][way]) && way == 0)
			return (ways);
		++way_array;
	}
	return (ways);
}