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

static void log_validation_errors(t_val_info *val_info, t_list **error_log)
{
	if (val_info->is_map_rectangular == FALSE)
		val_info->is_valid = log_error_message(error_log, MAP_NOT_RECTANGULAR_ERR, TRUE);
	if (val_info->is_surrounded_with_walls == FALSE)
		val_info->is_valid = log_error_message(error_log, WALLS_SURROUNDED_ERR, TRUE);
	if (val_info->players_count != 1)
		val_info->is_valid = log_error_message(error_log, PLAYERS_COUNT_ERR, TRUE);
	if (val_info->collectables_count < 1)
		val_info->is_valid = log_error_message(error_log, COLLECTABLES_COUNT_ERR, TRUE);
	if (val_info->collectables_count != 1)
		val_info->is_valid = log_error_message(error_log, EXITS_COUNT_ERR, TRUE);
}

static void validate_layout_size(const t_obj_type *const *buffer, t_val_info **val_info)
{
    int y;
    int mem_x;
    int x;

    y = 0;
    mem_x = 0;
    x = 0;
    while (buffer[y][mem_x] != EMPTY)
	    mem_x++;
    while (buffer[y])
    {
        x = 0;
        while (buffer[y][x] != EMPTY)
	        x++;
	    (*val_info)->is_map_rectangular = mem_x != x;
        y++;
    }
	(*val_info)->is_map_rectangular = x > y;
}

static void validate_layout_walls(const t_obj_type *const *buffer, t_temp_size temp_size, t_val_info **val_info)
{
	while (buffer[temp_size.rows])
	{
		temp_size.columns = 0;
		while (buffer[temp_size.rows][temp_size.columns] != EMPTY)
			temp_size.columns++;
		temp_size.rows++;
	}
	while (temp_size.x < temp_size.columns)
	{
		if (buffer[0][temp_size.x] != WALL || buffer[(temp_size.rows - 1)][temp_size.x] != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		temp_size.x++;
	}
	while (temp_size.y < (temp_size.rows - 1))
	{
		if (buffer[temp_size.y][0] != WALL || buffer[temp_size.y][(temp_size.columns - 1)] != WALL)
			(*val_info)->is_surrounded_with_walls = FALSE;
		temp_size.y++;
	}
}

static void count_objs(const t_obj_type *const *buffer, t_val_info **val_info)
{
	int y;
	int x;

	y = 0;
	while (buffer[y])
	{
		x = 0;
		while (buffer[y][x] != EMPTY)
		{
			if (buffer[y][x] == PLAYER)
				(*val_info)->players_count++;
			if (buffer[y][x] == COLLECTABLE)
				(*val_info)->collectables_count++;
			if (buffer[y][x] == EXIT)
				(*val_info)->exits_count++;
			x++;
		}
		y++;
	}
}

int is_layout_valid(const t_obj_type *const *buffer, t_list **error_log)
{
	t_val_info    *val_info;

	val_info = (t_val_info *)malloc(sizeof(t_val_info *));
	if (!val_info)
		return (log_error_message(error_log, UNKNOWN_ERR, TRUE));
	*val_info = (t_val_info){TRUE, TRUE, TRUE, 0, 0, 0};
	validate_layout_size(buffer, &val_info);
	if (val_info->is_map_rectangular)
		validate_layout_walls(buffer, (t_temp_size){0, 1, 0, 0}, &val_info);
	count_objs(buffer, &val_info);
	log_validation_errors(val_info, error_log);
	return (val_info->is_valid);
}
