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

int	brush_width = 16;
int	brush_height = 16;
int	follow = FALSE;

int	read_keys(int key_pressed, void *param)
{
	printf("key_pressed %d\n", key_pressed);
	if (key_pressed == COLOR)
	{
		if (follow == FALSE)
			follow = TRUE;
		else
			follow = FALSE;
	}
	(void)param;
	printf("follow %d\n", follow);
	return (0);
}

int	trigger_drawing(int button)
{
	if (button == 1)
		follow = TRUE;
	return (0);
}

int	cancel_drawing(int button)
{
	if (button == 1)
		follow = FALSE;
	return (0);
}

int	follow_mouse(unsigned int mouse_x, unsigned int mouse_y, void *param)
{
	t_img	*img;
	t_shape	shape;

	img = (t_img *)param;
	if (!img)
		return (ERROR);
	if (mouse_x < 0 || mouse_y < 0 || mouse_x > img->win.width || mouse_y > img->win.height)
		return (2);
	if (follow == FALSE)
		return (3);
	shape = (t_shape){0, 0, img->width, img->height, generate_color(255, 0, 0, 255)};
	draw_shape(shape, *img);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, mouse_x, mouse_y);
	return (0);
}

int	main(void)
{
	int		red;
	int		green;
	int		blue;
	t_win	window;
	t_img	image;

	red = generate_color(255, 255, 0, 0);
	green = generate_color(255, 0, 255, 0);
	blue = generate_color(255, 0, 0, 255);
	window = generate_window(800, 600, "so_long");
	if (!window.mlx_ptr || !window.win_ptr)
		return (1);
	image = generate_image(brush_width, brush_height, window);
	mlx_key_hook(window.win_ptr, read_keys, &image);
	mlx_hook(window.win_ptr, 4, 0, trigger_drawing, &image);
	mlx_hook(window.win_ptr, 5, 0, cancel_drawing, &image);
	mlx_hook(window.win_ptr, 6, 0, follow_mouse, &image);
	mlx_loop(window.mlx_ptr);
	return (0);
}
