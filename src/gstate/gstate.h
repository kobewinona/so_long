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
# include "../layout/layout.h"
# include "../map_validator/map_validator.h"
# include "../sprite_handler/sprite_handler.h"

typedef struct s_gstate
{
	t_win			*window;
	t_list			**error_log;
	t_layout		*layout;
	t_obj_type		*types_table;
	t_obj			**buffer;
	t_img			**sprites;
	t_xy			p_pos;
	int				coll_count;
}	t_gstate;

int	render_game(t_gstate *gstate);
int	render_layout(t_gstate	*gstate);
int	render_player(t_gstate *gstate);
int		init_game(const char *mapfile, t_list **error_log);
int		init_game_buffer(const char *mapfile, t_obj ***buffer, t_gdata gdata);
void	cleanup_game(void **ptr);

#endif
