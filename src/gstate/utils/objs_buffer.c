/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:54:38 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/25 15:54:38 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gstate.h"

static void	fill_buffer(
		const t_obj_type *types_buffer, t_obj **layout_buffer, t_img **sprites)
{
	t_obj_type	type;
	int			x;

	x = 0;
	while (types_buffer[x] != END)
	{
		type = types_buffer[x];
		if (type == PLAYER || type == COLLECTABLE)
			(*layout_buffer)[x] = create_object(type, sprites[type]);
		else
			(*layout_buffer)[x] = (t_obj){EMPTY, NULL, FALSE};
		x++;
	}
	(*layout_buffer)[x].type = END;
}

int	init_objs_buffer(
		t_obj_type **types_buffer, t_obj ***objs_buffer, t_gdata gdata)
{
	int	y;

	(*objs_buffer) = (t_obj **)ft_calloc(
			(gdata.size.height + 1), sizeof(t_obj *));
	if (!(*objs_buffer))
		return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
	y = 0;
	while (types_buffer[y])
	{
		(*objs_buffer)[y] = (t_obj *)ft_calloc(
				(gdata.size.width + 1), sizeof(t_obj));
		if (!(*objs_buffer)[y])
			return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
		fill_buffer(types_buffer[y], &(*objs_buffer)[y], gdata.sprites);
		y++;
	}
	return (SUCCESS);
}