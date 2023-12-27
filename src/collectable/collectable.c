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

void	destroy_collectable(t_list ***layers_buffer, t_xy pos)
{
	t_list	*prev;
	t_list	*current;
	t_list	*node_to_delete;

	prev = NULL;
	current = layers_buffer[pos.y][pos.x];
	while (current)
	{
		if (get_object(current)->type == COLLECTABLE)
		{
			node_to_delete = current;
			if (prev == NULL)
				layers_buffer[pos.y][pos.x] = current->next;
			else
				prev->next = current->next;
			ft_lstdelone(node_to_delete, free);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	update_collectables_count(
			t_obj_type **game_buffer, t_xy p_pos, int *collectables_count)
{
	if (game_buffer[p_pos.y][p_pos.x] == COLLECTABLE)
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
