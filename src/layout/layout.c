/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:46:16 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:17 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "layout.h"

static void	define_layout_size(
		t_size size, t_layout **layout, t_obj **game_buffer)
{
	while (game_buffer[size.height])
	{
		while (game_buffer[size.height][size.width].type != END)
			size.width++;
		size.height++;
	}
	(*layout)->width = size.width;
	(*layout)->height = size.height;
}

int	create_layout(t_layout **layout, t_obj **game_buffer, t_list **error_log)
{
	*layout = (t_layout *)malloc(sizeof(t_layout));
	if (!(*layout))
		return (log_error_message(error_log, UNKNOWN_ERR, ERROR));
	define_layout_size((t_size){0, 0}, layout, game_buffer);
	(*layout)->buffer = NULL;
	if (init_layout_buffer(
			game_buffer, &(*layout)->buffer, (t_size){
			(*layout)->width, (*layout)->height}, error_log) != SUCCESS)
		return (log_error_message(error_log, BUFFER_ERR, ERROR));
	return (SUCCESS);
}
