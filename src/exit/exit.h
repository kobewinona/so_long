/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:43:37 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "so_long.h"
# include "../object/object.h"
# include "../draw_shape/draw_shape.h"

t_img	*create_close_exit_sprite(void *mlx_ptr, t_list **error_log);
t_img	*create_open_exit_sprite(void *mlx_ptr, t_list **error_log);
int		is_exit_reached(t_list ***layers_buffer, t_xy pos);

#endif
