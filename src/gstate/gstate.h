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
# include "../buffer_handler/buffer_handler.h"
# include "../map_validator/map_validator.h"
# include "../sprite_handler/sprite_handler.h"

typedef struct s_gstate
{
	t_win			*window;
	t_size			size;
	t_list			**error_log;
	t_obj_type		*types_table;
	t_obj_type		**types_buffer;
	t_obj			**layout_buffer;
	t_obj			**objs_buffer;
	t_img			**sprites;
	t_xy			p_pos;
	int				collectables_count;
}	t_gstate;

int		init_game(const char *mapfile, t_list **error_log);
int		init_types_buffer(const char *mapfile,
			t_obj_type ***buffer, t_size *size, t_gdata gdata);
int		init_layout_buffer(
			t_obj_type **types_buffer, t_obj ***layout_buffer, t_gdata gdata);
int		init_objs_buffer(
			t_obj_type **types_buffer, t_obj ***objs_buffer, t_gdata gdata);
int		cleanup_game(void **ptr);
int		render_game(t_gstate **gstate);
int		render_layout(t_gstate	**gstate);
int		render_objects(t_gstate **gstate);

#endif
