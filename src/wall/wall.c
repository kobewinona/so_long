/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:01:20 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:01:20 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

//static void	cleanup(t_wall **wall, void *mlx_ptr)
//{
//	if ((*wall))
//	{
//		if ((*wall)->sprite)
//			mlx_destroy_image(mlx_ptr, (*wall)->sprite->img_ptr);
//		free((*wall));
//	}
//}
//
//static void	render(t_win *window, t_xy position, t_wall *wall)
//{
//	mlx_put_image_to_window(
//		window->mlx_ptr, window->win_ptr,
//		wall->sprite->img_ptr,
//		(position.x * SPRITE_WIDTH), (position.y * SPRITE_HEIGHT));
//}
//
//int	create_wall(t_wall **wall, void *mlx_ptr, t_list **error_log)
//{
//	*wall = (t_wall *)malloc(sizeof(t_wall));
//	if (!(*wall))
//		return (log_error_message(error_log, CREATE_WALL_ERR, ERROR));
//	(*wall)->collision = TRUE;
//	(*wall)->size = (t_size){SPRITE_WIDTH, SPRITE_HEIGHT};
//	(*wall)->color = create_color(255, 221, 115, 115);
//	(*wall)->sprite = create_image(
//			(*wall)->size.width, (*wall)->size.height, mlx_ptr);
//	if (!(*wall)->sprite)
//		return (log_error_message(error_log, CREATE_WALL_ERR, ERROR));
//	draw_shape((t_shape){
//		0, 0, (*wall)->size.width, (*wall)->size.height, (*wall)->color
//	}, (t_xy){0, 0}, *((*wall)->sprite));
//	(*wall)->render = &render;
//	(*wall)->cleanup = &cleanup;
//	return (SUCCESS);
//}

t_img	*create_wall_sprite(t_gdata gdata)
{
	t_img	*sprite;

	sprite = create_image(SPRITE_WIDTH, SPRITE_HEIGHT, gdata.window->mlx_ptr);
	if (!sprite)
	{
		log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR);
		return (NULL);
	}
	draw_shape((t_shape){0, 0, SPRITE_WIDTH,
		SPRITE_HEIGHT, create_color(255, 221, 115, 115)},
		(t_xy){0, 0}, *sprite);
	return (sprite);
}
