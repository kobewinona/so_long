/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodandfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:16:50 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/14 13:16:51 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "floodandfill.h"

static int cleanup_on_exit(t_ff **ff, int return_value)
{
	int y;

	if (ff && *ff)
	{
		y = 0;
		if ((*ff)->buffer)
		{
			while ((*ff)->buffer[y])
			{
				free((*ff)->buffer[y]);
				y++;
			}
			free((*ff)->buffer);
		}
		free(*ff);
	}
	return (return_value);
}

static bool **init_ff_buffer(const t_obj_type *const *buffer, t_xy_size temp)
{
	bool    **ff_buffer;

	ff_buffer = (bool **)ft_calloc((temp.height + 1), sizeof(bool *));
	if (!ff_buffer)
		return (NULL);
	while (temp.y < temp.height)
	{
		ff_buffer[temp.y] = (bool *)malloc((temp.width * sizeof(bool)));
		if (!ff_buffer[temp.y])
			return (NULL);
		temp.x = 0;
		while (temp.x < temp.width)
		{
			ff_buffer[temp.y][temp.x] = buffer[temp.y][temp.x] == WALL;
			temp.x++;
		}
		temp.y++;
	}
	return (ff_buffer);
}

static void find_player_position(t_ff **ff, const t_obj_type *const *buffer)
{
	while (buffer[(*ff)->players_y])
	{
		(*ff)->players_x = 0;
		while (buffer[(*ff)->players_y][(*ff)->players_x] != EMPTY)
		{
			if (buffer[(*ff)->players_y][(*ff)->players_x] == PLAYER)
				return ;
			(*ff)->players_x++;
		}
		(*ff)->players_y++;
	}
}

static void floodandfill(const t_obj_type *const *buffer, t_ff **ff, t_xy_size temp) // NOLINT(*-no-recursion)
{
	if (temp.x < 0 || temp.x >= temp.width || temp.y < 0 || temp.y >= temp.height)
		return ;
	if ((*ff)->buffer[temp.y][temp.x] == TRUE)
		return ;
	(*ff)->buffer[temp.y][temp.x] = TRUE;
	if (buffer[temp.y][temp.x] == COLLECTABLE)
		(*ff)->collectables_count--;
	else if (buffer[temp.y][temp.x] == EXIT)
		(*ff)->is_exit_found = TRUE;
	floodandfill(buffer, ff,(t_xy_size){(temp.x + 1), temp.y, temp.width, temp.height});
	floodandfill(buffer, ff, (t_xy_size){(temp.x - 1), temp.y, temp.width, temp.height});
	floodandfill(buffer, ff, (t_xy_size){temp.x, (temp.y + 1), temp.width, temp.height});
	floodandfill(buffer, ff, (t_xy_size){temp.x, (temp.y - 1), temp.width, temp.height});
}

int is_layout_solvable(const t_obj_type *const *buffer, t_val_info *val_info, t_list **error_log)
{
	t_ff    *ff;

	ff = (t_ff *)malloc(sizeof(t_ff));
	if (!ff)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	*ff = (t_ff){
		init_ff_buffer(buffer, (t_xy_size){0, 0, val_info->columns, val_info->rows}),
		0, 0, val_info->collectables_count, FALSE};
	if (!ff->buffer)
		return (cleanup_on_exit(&ff, log_error_message(error_log, UNKNOWN_ERR, ERROR)));
	find_player_position(&ff, buffer);
	floodandfill(buffer, &ff, (t_xy_size){ff->players_x, ff->players_y, val_info->columns, val_info->rows});
	return (cleanup_on_exit(&ff, ff->collectables_count == 0 && ff->is_exit_found));
}
