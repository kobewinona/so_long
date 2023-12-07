/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:23:25 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:23:26 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_buffer(t_win *window)
{
	int				rows;
	int				columns;
	unsigned int	x;
	unsigned int	y;

	rows = WINDOW_HEIGHT / TILE_HEIGHT;
	columns = WINDOW_WIDTH / TILE_WIDTH;
	window->buffer = malloc((rows * sizeof(t_buffer **)));
	y = 0;
	while (y < rows)
	{
		window->buffer[y] = malloc((columns * sizeof(t_buffer *)));
		x = 0;
		while (x < columns)
		{
			window->buffer[y][x].img = NULL;
			x++;
		}
		y++;
	}
}

t_win	create_window(char *title)
{
	t_win	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(
			window.mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			title);
	window.width = WINDOW_WIDTH;
	window.height = WINDOW_HEIGHT;
	init_buffer(&window);
	return (window);
}
