/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:14:30 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 19:14:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GSTATE_H
# define GSTATE_H
# include "so_long.h"
# include <stdio.h>
# include "../object/object.h"
# include "../exit/exit.h"
# include "../buffer_handler/buffer_handler.h"
# include "../map_validator/map_validator.h"
# include "../sprite_handler/sprite_handler.h"
# include "../keys_reader/keys_reader.h"

typedef struct s_gstate
{
	t_win			*window;
	t_size			size;
	t_list			**error_log;
	t_obj_type		*types_table;
	t_obj_type		**game_buffer;
	t_obj_type		**layout_buffer;
	t_list			***layers_buffer;
	t_img			**sprites;
	t_xy			p_pos;
	int				moves_count;
	int				collectables_count;
}	t_gstate;

int		init_game(const char *mapfile, t_list **error_log);
int		init_game_buffer(const char *mapfile,
			t_obj_type ***buffer, t_size *size, t_gdata gdata);
int		init_layout_buffer(t_obj_type **game_buffer,
			t_obj_type ***layout_buffer, t_gdata gdata);
int		init_layers_buffer(
			t_obj_type **game_buffer, t_list ****layers_buffer, t_gdata gdata);
void	cleanup_layers_buffer(t_list ***layers_buffer);
int		render_game(t_gstate **gstate);
int		cleanup_game(void **ptr);

#endif
