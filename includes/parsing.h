/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 09:12:42 by cbaillat          #+#    #+#             */
/*   Updated: 2018/03/02 12:51:32 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lem_in.h"

# define INVALID	(int8_t)-1

typedef struct	s_input
{
	char	**lines;
	int32_t	nb_lines;
}				t_input;

int64_t			get_ants(t_input *input, uint8_t flags);
int8_t			get_rooms(t_map *map, t_input *input, uint8_t flags);
int8_t			parse_map(t_map *map, t_input *input, uint8_t flags);
int8_t			parse_room(char *line, t_map *map, int8_t room_type);
int8_t			parse_tube(char *line, t_map *map);
int8_t			parse_type(char *cmd_line);
void			print_and_free_input(t_input input);
int8_t			save_line(char *line, t_input *input);

#endif
