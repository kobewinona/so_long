/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:21 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 12:14:23 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

static int	validate_layout_size(
		t_obj_type **buffer, t_xy pos, t_vdata vdata)
{
	int	mem_x;

	mem_x = 0;
	vdata.is_rectangular = TRUE;
	while (buffer[pos.y][mem_x] != END)
		mem_x++;
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x] != END)
			pos.x++;
		if (mem_x != pos.x)
			return (mem_x == pos.x);
		pos.y++;
	}
	return (pos.x > pos.y);
}

static t_vdata	validate_layout_walls(
		t_obj_type **buffer, t_xy pos, t_size size, t_vdata vdata)
{
	while (buffer[size.height])
	{
		size.width = 0;
		while (buffer[size.height][size.width] != END)
			size.width++;
		size.height++;
	}
	vdata.width = size.width;
	vdata.height = size.height;
	while (pos.x < size.width)
	{
		if (buffer[0][pos.x] != WALL
			|| buffer[size.height - 1][pos.x] != WALL)
		{
			vdata.is_surrounded_with_walls = FALSE;
			return (vdata);
		}
		pos.x++;
	}
	while (pos.y < (size.height - 1))
	{
		if (buffer[pos.y][0] != WALL
			|| buffer[pos.y][(size.width - 1)] != WALL)
		{
			vdata.is_surrounded_with_walls = FALSE;
			return (vdata);
		}
		pos.y++;
	}
	return (vdata);
}

static t_vdata	count_objs(t_obj_type **buffer, t_xy pos, t_vdata vdata)
{
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x] != END)
		{
			if (buffer[pos.y][pos.x] == PLAYER)
				vdata.players_count++;
			if (buffer[pos.y][pos.x] == COLLECTABLE)
				vdata.collectables_count++;
			if (buffer[pos.y][pos.x] == EXIT)
				vdata.exits_count++;
			pos.x++;
		}
		pos.y++;
	}
	return (vdata);
}

int	is_map_valid(t_obj_type **buffer, t_list **error_log)
{
	t_vdata	vdata;

	vdata = (t_vdata){
		TRUE, TRUE, TRUE,
		0, 0, 0, TRUE, 0, 0};
	vdata.is_rectangular = validate_layout_size(buffer, (t_xy){0, 0}, vdata);
	if (vdata.is_rectangular)
		vdata = validate_layout_walls(
				buffer, (t_xy){0, 1}, (t_size){0, 0}, vdata);
	vdata = count_objs(buffer, (t_xy){0, 0}, vdata);
	vdata.is_solvable = is_map_solvable(buffer, vdata, error_log);
	if (vdata.is_solvable == ERROR)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	return (log_validation_errors(vdata, error_log));
}
