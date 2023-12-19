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

static void	cleanup(t_exit **exit, void *mlx_ptr)
{
	if ((*exit))
	{
		if ((*exit)->sprite)
			mlx_destroy_image(mlx_ptr, (*exit)->sprite->img_ptr);
		free((*exit));
	}
}

static void	render(t_win *window, t_xy position, t_exit *exit)
{
	mlx_put_image_to_window(
		window->mlx_ptr, window->win_ptr,
		exit->sprite->img_ptr,
		(position.x * SPRITE_WIDTH), (position.y * SPRITE_HEIGHT));
}

int	create_exit(t_exit **exit, void *mlx_ptr, t_list **error_log)
{
	*exit = (t_exit *)malloc(sizeof(t_exit));
	if (!(*exit))
		return (log_error_message(error_log, CREATE_WALL_ERR, ERROR));
	(*exit)->collision = TRUE;
	(*exit)->size = (t_size){SPRITE_WIDTH, SPRITE_HEIGHT};
	(*exit)->color = create_color(255, 59, 53, 97);
	(*exit)->sprite = create_image(
			(*exit)->size.width, (*exit)->size.height, mlx_ptr);
	if (!(*exit)->sprite)
		return (log_error_message(error_log, CREATE_WALL_ERR, ERROR));
	draw_shape((t_shape){0, 0, (*exit)->size.width,
		(*exit)->size.height, (*exit)->color},
		(t_xy){0, 0}, *((*exit)->sprite));
	(*exit)->render = &render;
	(*exit)->cleanup = &cleanup;
	return (SUCCESS);
}
