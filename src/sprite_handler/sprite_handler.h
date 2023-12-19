/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:43:07 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/20 00:43:07 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_HANDLER_H
# define SPRITE_HANDLER_H
# include "so_long.h"
# include "gdata.h"
# include "../types_table/types_table.h"
# include "../player/player.h"
# include "../wall/wall.h"
# include "../collectable/collectable.h"
# include "../exit/exit.h"

int		create_sprites(t_img ***sprites, t_gdata gdata);
t_img	*create_sprite(t_obj_type type, t_gdata gdata);
void	cleanup_sprites(
			void *mlx_ptr, t_obj_type *types_table, t_img ***sprites);

#endif