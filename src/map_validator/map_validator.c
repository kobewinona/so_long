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

static int	cleanup_on_exit(t_val_info **val_info, int return_value)
{
	if (val_info && *val_info)
		free(*val_info);
	return (return_value);
}

static void	validate_layout_size(
		t_obj **buffer, t_xy pos, t_val_info **val_info)
{
	int	mem_x;

	mem_x = 0;
	(*val_info)->is_rectangular = TRUE;
	while (buffer[pos.y][mem_x].type != END)
		mem_x++;
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != END)
			pos.x++;
		if (mem_x != pos.x)
		{
			(*val_info)->is_rectangular = mem_x == pos.x;
			return ;
		}
		pos.y++;
	}
	(*val_info)->is_rectangular = pos.x > pos.y;
}

static void	validate_layout_walls(
		t_obj **buffer, t_xy pos, t_size size, t_val_info **val_info)
{
	while (buffer[size.height])
	{
		size.width = 0;
		while (buffer[size.height][size.width].type != END)
			size.width++;
		size.height++;
	}
	(*val_info)->width = size.width;
	(*val_info)->height = size.height;
	while (pos.x < size.width)
	{
		if (buffer[0][pos.x].type != WALL
			|| buffer[size.height - 1][pos.x].type != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		pos.x++;
	}
	while (pos.y < (size.height - 1))
	{
		if (buffer[pos.y][0].type != WALL
			|| buffer[pos.y][(size.width - 1)].type != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		pos.y++;
	}
}

static void	count_objs(
		t_obj **buffer, t_xy pos, t_val_info **val_info)
{
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != END)
		{
			if (buffer[pos.y][pos.x].type == PLAYER)
				(*val_info)->players_count++;
			if (buffer[pos.y][pos.x].type == COLLECTABLE)
				(*val_info)->collectables_count++;
			if (buffer[pos.y][pos.x].type == EXIT)
				(*val_info)->exits_count++;
			pos.x++;
		}
		pos.y++;
	}
}

int	is_map_valid(t_obj **buffer, t_list **error_log)
{
	t_val_info	*val_info;

	val_info = (t_val_info *)malloc(sizeof(t_val_info));
	if (!val_info)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	*val_info = (t_val_info){
		TRUE, TRUE, TRUE,
		0, 0, 0, TRUE, 0, 0};
	validate_layout_size(buffer, (t_xy){0, 0}, &val_info);
	if (val_info->is_rectangular)
		validate_layout_walls(buffer, (t_xy){0, 1}, (t_size){0, 0}, &val_info);
	count_objs(buffer, (t_xy){0, 0}, &val_info);
	val_info->is_solvable = is_map_solvable(buffer, val_info, error_log);
	if (val_info->is_solvable == ERROR)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	log_validation_errors(val_info, error_log);
	return (cleanup_on_exit(&val_info, val_info->is_valid));
}
