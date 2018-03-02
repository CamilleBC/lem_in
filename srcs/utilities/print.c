/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:11:03 by cbaillat          #+#    #+#             */
/*   Updated: 2018/03/02 16:11:11 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utilities.h"

void	print_input(t_input input)
{
	int32_t	i;

	i = 0;
	while (i < input.nb_lines)
	{
		ft_print("%s\n", input.lines[i]);
		++i;
	}
}

void	print_way(t_way *way)
{
	if (!way)
		return ;
	ft_print("%s -> ", way->room->name);
	way = way->next;
	while (way && way->room->type != END)
	{
		ft_print("%s -> ", way->room->name);
		way = way->next;
	}
	ft_print("%s\n", way->room->name);
}

void	print_ways(t_way **ways)
{
	size_t	i;
	if (!ways)
		return ;
	i = 0;
	while (ways[i])
	{
		print_way(ways[i]);
		++i;
	}
}

//debug
void	print_links(t_room *room)
{
	size_t	i;

	i = 0;
	ft_print("Room #%s links:\n", room->name);
	while(i < room->size_links)
	{
		ft_print("link #%d: %s\n", i, room->links[i]->name);
		++i;
	}
}