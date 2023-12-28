/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:43:31 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:33 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

int	is_exit_reached(t_list ***layers_buffer, t_xy pos)
{
	t_list	*current;

	current = layers_buffer[pos.y][pos.x];
	while (current)
	{
		if (get_object(current)->type == EXIT)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

t_img	*create_open_exit_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_file_image("./assets/exit/ladder.xpm", mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	return (sprite);
}

t_img	*create_close_exit_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_file_image("./assets/exit/key_block.xpm", mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	return (sprite);
}
