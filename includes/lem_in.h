/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 08:43:41 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/22 13:54:05 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>
# include <stdlib.h>
# include "libft.h"

# define ROOM	(int8_t)0
# define START	(int8_t)1
# define END	(int8_t)2

# define DEF_LINKS_ALLOC 16

typedef struct	s_room
{
	char			*name;
	int8_t			type;
	int64_t			x;
	int64_t			y;
	struct s_room	**links;
	uint64_t		size_links;
	uint64_t		alloc_links;
	uint8_t			full;
}				t_room;

typedef struct	s_map
{
	t_room		**rooms;
	uint64_t	size_rooms;
	uint64_t	ways;
	int64_t		ants;
}				t_map;

typedef struct	s_way
{
	t_room			*room;
	struct s_way	*next;
}				t_way;

#endif
