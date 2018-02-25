/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:02:25 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/25 13:02:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGER_H
# define ERROR_MANAGER_H

# include "algorithm.h"
# include "lem_in.h"
# include "parsing.h"

void	*error_flow_control(uint64_t nb_ways, t_way ***ways);
int8_t	error_parsing(t_input *to_print, t_map *map);
int8_t	error_parsing_room(t_room *room);
int8_t	error_parsing_tube(char *name);

#endif
