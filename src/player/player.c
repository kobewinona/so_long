/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:52:39 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 14:52:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

static void	update_player_position(
		t_list ***layers_buffer, t_xy curr_pos, t_xy new_pos)
{
	t_list	*prev;
	t_list	*current;

	prev = NULL;
	current = layers_buffer[curr_pos.y][curr_pos.x];
	while (current)
	{
		if (get_object(current)->type == PLAYER)
		{
			if (prev == NULL)
				layers_buffer[curr_pos.y][curr_pos.x] = current->next;
			else
				prev->next = current->next;
			current->next = NULL;
			ft_lstadd_back(&layers_buffer[new_pos.y][new_pos.x], current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static int	is_collision(t_list *current)
{
	while (current)
	{
		if (get_object(current)->type == WALL)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}

void	move_player(t_list ***layers_buffer, t_xy *curr_pos, int key_pressed)
{
	int		dir_y;
	int		dir_x;
	t_xy	new_pos;

	dir_y = (key_pressed == S) - (key_pressed == W);
	dir_x = (key_pressed == D) - (key_pressed == A);
	new_pos = (t_xy){(curr_pos->x + dir_x), (curr_pos->y + dir_y)};
	if (is_collision(layers_buffer[new_pos.y][new_pos.x]) == TRUE)
		return ;
	destroy_collectable(layers_buffer, new_pos);
	update_player_position(layers_buffer, *curr_pos, new_pos);
	*curr_pos = new_pos;
}

t_img	*create_player_sprite(void *mlx_ptr, t_list **error_log)
{
	t_img	*sprite;

	sprite = create_file_image("./assets/player/player_idle.xpm", mlx_ptr);
	if (!sprite)
	{
		log_error_message(error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	return (sprite);
}
