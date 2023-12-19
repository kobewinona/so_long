/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:52:45 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/04 14:52:47 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "so_long.h"
# include "../draw_shape/draw_shape.h"

t_img	*create_player_sprite(void *mlx_ptr, t_list **error_log);

#endif
