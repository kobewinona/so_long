/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:49 by dklimkin          #+#    #+#             */
/*   Updated: 2023/11/29 16:46:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_keys(int key_pressed, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (key_pressed == W)
		player->obj.y -= player->height;
	if (key_pressed == A)
		player->obj.x -= player->width;
	if (key_pressed == S)
		player->obj.y += player->height;
	if (key_pressed == D)
		player->obj.x += player->width;
	// draw_player(player);
	return (1);
}

int	main(void)
{
	t_win		window;

	window = create_window(TITLE);
	if (!window.mlx_ptr || !window.win_ptr || !window.buffer)
		exit(EXIT_FAILURE);
	// mlx_key_hook(window.win_ptr, read_keys, &player);
	mlx_loop(window.mlx_ptr);
	return (0);
}
