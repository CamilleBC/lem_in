/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:34 by cbaillat          #+#    #+#             */
/*   Updated: 2018/03/02 17:15:15 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_manager.h"
#include "parsing.h"
#include "utilities.h"

static int8_t	find_and_replace_room(t_map *map, t_room room)
{
	uint64_t	i;

	if (!map->rooms)
		return (ERROR);
	i = 0;
	while (i < map->size_rooms)
	{
		if (!ft_strcmp(map->rooms[i]->name, room.name))
		{
			map->rooms[i]->type = room.type;
			map->rooms[i]->x = room.x;
			map->rooms[i]->y = room.y;
			return (SUCCESS);
		}
		++i;
	}
	return (ERROR);
}

static char		*get_room_name(char *line, size_t *idx)
{
	size_t		idx_end;
	char		*res;

	while (line[*idx] && ft_isspace(line[*idx]))
		*idx += 1;
	idx_end = *idx;
	while (line[idx_end] && !ft_isspace(line[idx_end]))
		idx_end++;
	res = ft_strsub(line, *idx, idx_end);
	*idx = idx_end;
	if (res[0] == 'L')
	{
		free(res);
		return (0);
	}
	return (res);
}

int64_t			get_coordinate(char *line, size_t *idx)
{
	int64_t		res;

	while (line[*idx] && ft_isspace(line[*idx]))
		*idx += 1;
	if (line[*idx] == 0 || !ft_isdigit(line[*idx]))
		return (ERROR);
	res = ft_atoi64(line + *idx);
	while (line[*idx] && !ft_isspace(line[*idx]))
		*idx += 1;
	return (res);
}

int8_t			parse_room(char *line, t_map *map, int8_t room_type)
{
	size_t	idx;
	t_room	*room;

	if (!line || *line == '\0' || map->size_rooms >= UINT32_MAX
			|| !(room = init_room()))
		return (ERROR);
	idx = 0;
	if ((room->name = get_room_name(line, &idx)) == NULL)
		return (error_parsing_room(room));
	if ((room->x = get_coordinate(line, &idx)) == ERROR)
		return (error_parsing_room(room));
	if ((room->y = get_coordinate(line, &idx)) == ERROR)
		return (error_parsing_room(room));
	while (line[idx] && ft_isspace(line[idx]))
		++idx;
	if (line[idx])
		return (error_parsing_room(room));
	room->type = room_type;
	if (find_and_replace_room(map, *room) == SUCCESS)
		free_room(room);
	else if (add_room(map, room) == ERROR)
		return (error_parsing_room(room));
	return (SUCCESS);
}

int8_t			parse_type(char *cmd_line)
{
	if (!(ft_strcmp(cmd_line, "start")))
		return (START);
	else if (!(ft_strcmp(cmd_line, "end")))
		return (END);
	return (ROOM);
}
