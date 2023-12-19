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
# include "../draw_shape/draw_shape.h"

t_img	*create_collectable_sprite(void *mlx_ptr, t_list **error_log);

#endif
