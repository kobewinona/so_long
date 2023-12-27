/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:54:11 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/25 15:54:12 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

static void	fill_buffer(
		const t_obj_type *game_buffer, t_obj_type **layout_buffer)
{
	t_obj_type	type;
	int			x;

	x = 0;
	while (game_buffer[x] != END)
	{
		type = game_buffer[x];
		if (type != PLAYER && type != COLLECTABLE)
			(*layout_buffer)[x] = game_buffer[x];
		x++;
	}
	(*layout_buffer)[x] = END;
}

int	init_layout_buffer(
		t_obj_type **game_buffer, t_obj_type ***layout_buffer, t_gdata gdata)
{
	int	y;

	(*layout_buffer) = (t_obj_type **)ft_calloc(
			(gdata.size.height + 1), sizeof(t_obj_type *));
	if (!(*layout_buffer))
		return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
	y = 0;
	while (game_buffer[y])
	{
		(*layout_buffer)[y] = (t_obj_type *)ft_calloc(
				(gdata.size.width + 1), sizeof(t_obj_type));
		if (!(*layout_buffer)[y])
			return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
		fill_buffer(game_buffer[y], &(*layout_buffer)[y]);
		y++;
	}
	return (SUCCESS);
}
