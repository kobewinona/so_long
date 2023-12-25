/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:39:18 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:39:18 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collectable.h"

void	update_collectables_count(
			t_obj_type **type_buffer, t_obj **layout_buffer,
			t_xy p_pos, int *collectables_count)
{
	if (type_buffer[p_pos.y][p_pos.x] == COLLECTABLE)
		(*collectables_count)--;
}

void	count_collectables(t_obj_type **buffer, int *collectables_count)
{
	t_xy	pos;

	pos = (t_xy){0, 0};
	(*collectables_count) = 0;
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x] != END)
		{
			if (buffer[pos.y][pos.x] == COLLECTABLE)
				(*collectables_count)++;
			pos.x++;
		}
		pos.y++;
	}
}

t_img	*create_collectable_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_file_image("./assets/collectable/key.xpm", mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	return (sprite);
}
