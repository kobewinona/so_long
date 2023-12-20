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

int	count_collectables(t_obj **buffer)
{
	int		count;
	t_xy	pos;

	count = 0;
	pos = (t_xy){0, 0};
	while (buffer[pos.y])
	{
		pos.x = 0;
		while (buffer[pos.y][pos.x].type != END)
		{
			if (buffer[pos.y][pos.x].type == COLLECTABLE)
				count++;
			pos.x++;
		}
		pos.y++;
	}
	return (count);
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
