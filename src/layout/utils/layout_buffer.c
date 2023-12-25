/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:31:47 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 15:31:48 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../layout.h"

static void	fill_layout_buffer(
		const t_obj *game_buffer, t_obj **layout_buffer, int y)
{
	int		i;

	i = 0;
	while (game_buffer[i].type != END)
	{
		if (game_buffer[i].type != PLAYER && game_buffer[i].type != COLLECTABLE)
			(*layout_buffer)[i] = game_buffer[i];
		else
			(*layout_buffer)[i] = (t_obj){EMPTY, NULL, FALSE};
		i++;
	}
	(*layout_buffer)[i].type = END;
}

int	init_layout_buffer(
		t_obj **game_buffer, t_obj ***layout_buffer,
		t_size size, t_list **error_log)
{
	int	i;

	(*layout_buffer) = (t_obj **)ft_calloc(
			(size.height + 1), sizeof(t_obj *));
	if (!(*layout_buffer))
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	i = 0;
	while (game_buffer[i])
	{
		(*layout_buffer)[i] = (t_obj *)ft_calloc(
				(size.width + 1), sizeof(t_obj));
		if (!(*layout_buffer)[i])
			return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
		fill_layout_buffer(game_buffer[i], &(*layout_buffer)[i], i);
		i++;
	}
	return (SUCCESS);
}
