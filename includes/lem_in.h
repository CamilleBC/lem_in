/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 08:43:41 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/28 15:28:40 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>
# include <stdlib.h>
# include "libft.h"

# define FOUND	(int8_t)-2
# define ROOM	(int8_t)0
# define START	(int8_t)1
# define END	(int8_t)2

# define DEF_LINKS_ALLOC 16

typedef struct	s_room
{
	char			*name;
	uint32_t		id;
	int8_t			type;
	int64_t			x;
	int64_t			y;
	uint8_t			visited;
	uint8_t			flow;
	struct s_room	*prev;
}				t_room;

typedef struct	s_map
{
	t_room		**rooms;
	uint32_t	size_rooms;
	uint64_t	*adj_matrix;
	uint64_t	ways;
	int64_t		ants;
}				t_map;

typedef struct	s_way
{
	t_room			*room;
	struct s_way	*next;
	struct s_way	*prev;
}				t_way;

//debug
void	print_reverse_way(t_room *end);
void	print_links(t_room room);
void	print_map(t_map map);
void	print_flow(t_map *map, uint32_t *flow);
void	print_path(int64_t *path, t_map *map);
void	print_room(t_room room);
void	print_way(t_way *way);

#endif
