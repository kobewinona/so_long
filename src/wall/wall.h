/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:01:27 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:01:28 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

t_img	*create_wall_sprite(void *mlx_ptr, t_list **error_log);

#endif
