/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 11:11:03 by cbaillat          #+#    #+#             */
/*   Updated: 2018/02/15 16:24:12 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int8_t	save_line(char *line, t_input *input)
{
	int32_t	nb_lines;

	nb_lines = input->nb_lines;
	if (!(input->lines = ft_realloc(input->lines,
										sizeof(char*) * nb_lines,
										sizeof(char*) * (nb_lines + 1))))
	{
		free(line);
		return (ERROR);
	}
	input->lines[nb_lines] = line;
	input->nb_lines += 1;
	return (SUCCESS);
}

void	print_and_free_input(t_input input)
{
	int32_t	i;

	i = 0;
	while (i < input.nb_lines)
	{
		ft_print("%s\n", input.lines[i]);
		free(input.lines[i]);
		++i;
	}
	free(input.lines);
}

//debug
void	print_input(t_input input)
{
	int32_t	i;

	i = 0;
	// We will not print the ;ast line as it will always be rubbish
	// while (i < input.nb_lines - 1)
	while (i < input.nb_lines)
	{
		ft_print("%s\n", input.lines[i]);
		++i;
	}
}

//debug
void	print_map(t_map map)
{
	uint64_t	i;

	i = 0;
	while (i < map.size_rooms)
	{
		ft_print("------------\nROOM #%d\n", (i + 1));
		ft_print("Name: %s\n", map.rooms[i]->name);
		if (map.rooms[i]->type == ROOM)
			ft_print("Type: room\n");
		else if (map.rooms[i]->type == START)
			ft_print("Type: start\n");
		else if (map.rooms[i]->type == END)
			ft_print("Type: end\n");
		else
			ft_print("Type: *unkown*\n");
		ft_print("X: %d\n", (int64_t)map.rooms[i]->x);
		ft_print("Y: %d\n", (int64_t)map.rooms[i]->y);
		++i;
	}
}

//debug
void	print_room(t_room room)
{
	uint64_t	i;

	ft_print("------------\nROOM\n");
	ft_print("Name: %s\n", room.name);
	if (room.type == ROOM)
		ft_print("Type: room\n");
	else if (room.type == START)
		ft_print("Type: start\n");
	else if (room.type == END)
		ft_print("Type: end\n");
	else
		ft_print("Type: *unkown*\n");
	ft_print("X: %d\n", (int64_t)room.x);
	ft_print("Y: %d\n", (int64_t)room.y);
	i = 0;
	while (i < room.size_links)
	{
		ft_print("Link #%d: %s\n", i, room.links[i]->name);
		++i;
	}
}

//debug
void	print_links(t_room room)
{
	uint64_t	i;

	ft_print("------------\nROOM LINKS\n");
	ft_print("Name: %s\n", room.name);
	i = 0;
	while (i < room.size_links)
	{
		ft_print("Link #%d: %s\n", i, room.links[i]->name);
		++i;
	}
}
