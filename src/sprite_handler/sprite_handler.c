/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:43:01 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/20 00:43:02 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_handler.h"

void	cleanup_sprites(void *mlx_ptr,
		t_obj_type *types_table, t_img ***sprites)
{
	int	types_count;
	int	i;

	types_count = count_valid_types(types_table);
	i = 0;
	while (i > types_count)
	{
		if ((*sprites)[i])
			mlx_destroy_image(mlx_ptr, (*sprites)[i]);
		i++;
	}
}

t_img	*create_sprite(t_obj_type type, t_gdata gdata)
{
	if (type == EMPTY)
		return (NULL);
	if (type == BACKGROUND)
		return (create_background_sprite(
				gdata.window->mlx_ptr, gdata.error_log));
	if (type == WALL)
		return (create_wall_sprite(gdata.window->mlx_ptr, gdata.error_log));
	if (type == PLAYER)
		return (create_player_sprite(gdata.window->mlx_ptr, gdata.error_log));
	if (type == COLLECTABLE)
		return (create_collectable_sprite(
				gdata.window->mlx_ptr, gdata.error_log));
	if (type == EXIT)
		return (create_close_exit_sprite(
				gdata.window->mlx_ptr, gdata.error_log));
	return (NULL);
}

int	create_sprites(t_img ***sprites, t_gdata gdata)
{
	int	types_count;
	int	type;

	types_count = count_valid_types(gdata.types_table);
	(*sprites) = (t_img **)ft_calloc((types_count + 1), sizeof(t_img *));
	if (!(*sprites))
		return (log_error_message(gdata.error_log, UNKNOWN_ERR, ERROR));
	type = 1;
	while (type < types_count)
	{
		(*sprites)[type] = create_sprite(type, gdata);
		if (type != EMPTY && !(*sprites)[type])
			return (log_error_message(gdata.error_log, SPRITE_ERR, ERROR));
		type++;
	}
	return (SUCCESS);
}
