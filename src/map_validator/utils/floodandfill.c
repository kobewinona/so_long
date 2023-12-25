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

#include "../map_validator.h"

static int	cleanup_on_exit(t_ff **ff, int return_value)
{
	int	y;

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

static bool	**init_ff_buffer(t_obj_type **buffer, t_xy pos, t_size size)
{
	bool	**ff_buffer;

	ff_buffer = (bool **)ft_calloc((size.height + 1), sizeof(bool *));
	if (!ff_buffer)
		return (NULL);
	while (pos.y < size.height)
	{
		ff_buffer[pos.y] = (bool *)malloc((size.width * sizeof(bool)));
		if (!ff_buffer[pos.y])
			return (NULL);
		pos.x = 0;
		while (pos.x < size.width)
		{
			ff_buffer[pos.y][pos.x] = buffer[pos.y][pos.x] == WALL;
			pos.x++;
		}
		pos.y++;
	}
	return (ff_buffer);
}

static void	find_player_position(t_ff **ff, t_obj_type **buffer)
{
	while (buffer[(*ff)->players_y])
	{
		(*ff)->players_x = 0;
		while (buffer[(*ff)->players_y][(*ff)->players_x] != END)
		{
			if (buffer[(*ff)->players_y][(*ff)->players_x] == PLAYER)
				return ;
			(*ff)->players_x++;
		}
		(*ff)->players_y++;
	}
}

static void	floodandfill(t_obj_type **buffer, t_ff **ff, t_xy pos, t_size size)
{
	if (pos.x < 0 || pos.x >= size.width
		|| pos.y < 0 || pos.y >= size.height)
		return ;
	if ((*ff)->buffer[pos.y][pos.x] == TRUE)
		return ;
	(*ff)->buffer[pos.y][pos.x] = TRUE;
	if (buffer[pos.y][pos.x] == COLLECTABLE)
		(*ff)->collectables_count--;
	else if (buffer[pos.y][pos.x] == EXIT)
		(*ff)->is_exit_found = TRUE;
	floodandfill(buffer, ff, (t_xy){
		(pos.x + 1), pos.y}, (t_size){size.width, size.height});
	floodandfill(buffer, ff, (t_xy){
		(pos.x - 1), pos.y}, (t_size){size.width, size.height});
	floodandfill(buffer, ff, (t_xy){
		pos.x, (pos.y + 1)}, (t_size){size.width, size.height});
	floodandfill(buffer, ff, (t_xy){
		pos.x, (pos.y - 1)}, (t_size){size.width, size.height});
}

int	is_map_solvable(t_obj_type **buffer, t_vdata vdata, t_list **error_log)
{
	t_ff	*ff;

	ff = (t_ff *)malloc(sizeof(t_ff));
	if (!ff)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	*ff = (t_ff){init_ff_buffer(buffer, (t_xy){
			0, 0}, (t_size){vdata.width, vdata.height}),
		0, 0, vdata.collectables_count, FALSE};
	if (!ff->buffer)
		return (cleanup_on_exit(
				&ff, log_error_message(error_log, UNKNOWN_ERR, ERROR)));
	find_player_position(&ff, buffer);
	floodandfill(buffer, &ff, (t_xy){ff->players_x, ff->players_y},
		(t_size){vdata.width, vdata.height});
	return (cleanup_on_exit(
			&ff, ff->collectables_count == 0 && ff->is_exit_found));
}
