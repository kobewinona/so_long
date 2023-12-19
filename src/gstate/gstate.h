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
# include "../types_table/types_table.h"
# include "../map_validator/map_validator.h"
# include "../player/player.h"
# include "../wall/wall.h"

typedef struct s_gstate
{
	t_win			*window;
	t_list			**error_log;
	t_layout		*layout;
	t_obj_type		*types_table;
	t_obj			**buffer;
	t_img			**sprites;
}	t_gstate;

int		init_game(const char *mapfile, t_list **error_log);
int		init_game_buffer(const char *mapfile, t_obj ***buffer, t_gdata gdata);
t_img	*create_sprite(t_obj_type type);
void	cleanup_game(void **ptr);

#endif
