/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:28 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/19 16:14:30 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "background.h"

static void	cleanup(t_background **background, void *mlx_ptr)
{
	if ((*background))
	{
		if ((*background)->sprite)
			mlx_destroy_image(mlx_ptr, (*background)->sprite->img_ptr);
		free((*background));
	}
}

static void	render(t_win *window, t_xy position, t_background *background)
{
	mlx_put_image_to_window(
		window->mlx_ptr, window->win_ptr,
		background->sprite->img_ptr,
		(position.x * SPRITE_WIDTH), (position.y * SPRITE_HEIGHT));
}

int	create_background(
		t_background **background, void *mlx_ptr, t_list **error_log)
{
	*background = (t_background *)malloc(sizeof(t_background));
	if (!(*background))
		return (log_error_message(error_log, CREATE_BACKGROUND_ERR, ERROR));
	(*background)->collision = FALSE;
	(*background)->size = (t_size){SPRITE_WIDTH, SPRITE_HEIGHT};
	(*background)->color = create_color(255, 209, 209, 209);
	(*background)->sprite = create_image(
			(*background)->size.width, (*background)->size.height, mlx_ptr);
	if (!(*background)->sprite)
		return (log_error_message(error_log, CREATE_BACKGROUND_ERR, ERROR));
	draw_shape((t_shape){0, 0, (*background)->size.width,
		(*background)->size.height, (*background)->color},
		(t_xy){0, 0}, *((*background)->sprite));
	(*background)->render = &render;
	(*background)->cleanup = &cleanup;
	return (SUCCESS);
}
