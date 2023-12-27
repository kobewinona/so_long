/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:39:23 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:39:24 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTABLE_H
# define COLLECTABLE_H
# include "so_long.h"
# include "../object/object.h"
# include "../draw_shape/draw_shape.h"

t_img	*create_collectable_sprite(void *mlx_ptr, t_list **error_log);
void	count_collectables(t_obj_type **buffer, int *collectables_count);
void	update_collectables_count(
			t_obj_type **game_buffer, t_xy p_pos, int *collectables_count);
void	destroy_collectable(t_list ***layers_buffer, t_xy pos);

#endif