/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:47:05 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 15:47:06 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "layout_validator.h"

static int	cleanup_on_exit(t_val_info **val_info, int return_value)
{
	if (val_info && *val_info)
		free(*val_info);
	return (return_value);
}

static void	validate_layout_size(
		const t_obj_type *const *buffer, t_xy temp, t_val_info **val_info)
{
	int	mem_x;

	mem_x = 0;
	while (buffer[temp.y][mem_x] != EMPTY)
		mem_x++;
	while (buffer[temp.y])
	{
		temp.x = 0;
		while (buffer[temp.y][temp.x] != EMPTY)
			temp.x++;
		(*val_info)->is_rectangular = mem_x != temp.x;
		temp.y++;
	}
	(*val_info)->is_rectangular = temp.x > temp.y;
}

static void	validate_layout_walls(
		const t_obj_type *const *buffer, t_xy_size temp, t_val_info **val_info)
{
	while (buffer[temp.height])
	{
		temp.width = 0;
		while (buffer[temp.height][temp.width] != EMPTY)
			temp.width++;
		temp.height++;
	}
	(*val_info)->rows = temp.height;
	(*val_info)->columns = temp.width;
	while (temp.x < temp.width)
	{
		if (buffer[0][temp.x] != WALL
			|| buffer[temp.height - 1][temp.x] != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		temp.x++;
	}
	while (temp.y < (temp.height - 1))
	{
		if (buffer[temp.y][0] != WALL
			|| buffer[temp.y][(temp.width - 1)] != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		temp.y++;
	}
}

static void	count_objs(
		const t_obj_type *const *buffer, t_xy temp, t_val_info **val_info)
{
	while (buffer[temp.y])
	{
		temp.x = 0;
		while (buffer[temp.y][temp.x] != EMPTY)
		{
			if (buffer[temp.y][temp.x] == PLAYER)
				(*val_info)->players_count++;
			if (buffer[temp.y][temp.x] == COLLECTABLE)
				(*val_info)->collectables_count++;
			if (buffer[temp.y][temp.x] == EXIT)
				(*val_info)->exits_count++;
			temp.x++;
		}
		temp.y++;
	}
}

int	is_layout_valid(const t_obj_type *const *buffer, t_list **error_log)
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
	{
		validate_layout_walls(buffer, (t_xy_size){0, 1, 0, 0}, &val_info);
	}
	count_objs(buffer, (t_xy){0, 0}, &val_info);
	val_info->is_solvable = is_layout_solvable(buffer, val_info, error_log);
	if (val_info->is_solvable == ERROR)
	{
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	}
	log_validation_errors(val_info, error_log);
	return (cleanup_on_exit(&val_info, val_info->is_valid));
}
