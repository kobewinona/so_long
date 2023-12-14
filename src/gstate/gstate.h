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
# include "../player/player.h"
# include "../ground/ground.h"

typedef struct s_gstate {
    t_layout    *layout;
    t_win		window;
    t_player	*player;
    t_ground	*ground;
	t_list      **error_log;
}	t_gstate;

int     init_game(const char *mapfile, t_list **error_log);
void    cleanup_game(void **ptr);

#endif
