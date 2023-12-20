/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:14:34 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/19 16:14:35 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

t_img	*create_background_sprite(void *mlx_ptr, t_list **error_log);

#endif
