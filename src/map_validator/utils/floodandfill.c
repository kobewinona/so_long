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

static bool	**init_ff_buffer(t_obj_type **buffer, t_size size)
{
	bool	**ff_buffer;
	t_xy	pos;

	ff_buffer = (bool **)ft_calloc((size.height + 1), sizeof(bool *));
	if (!ff_buffer)
		return (NULL);
	pos = (t_xy){0, 0};
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

int	is_solvable(t_obj_type **buffer,
		t_vdata vdata, t_size size, t_list **error_log)
{
	t_ff	*ff;

	ff = (t_ff *)malloc(sizeof(t_ff));
	if (!ff)
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	ft_memset(ff, 0, sizeof(t_ff));
	ff->buffer = init_ff_buffer(buffer, size);
	if (!ff->buffer)
		return (cleanup_on_exit(&ff, log_error_message(
					error_log, UNKNOWN_ERR, ERROR)));
	ff->collectables_count = vdata.collectables_count;
	find_buffer_type(buffer, &ff->p_pos, PLAYER);
	floodandfill(buffer, &ff, ff->p_pos, size);
	return (cleanup_on_exit(&ff,
			ff->collectables_count == 0 && ff->is_exit_found));
}
