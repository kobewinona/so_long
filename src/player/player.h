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
# include <stdlib.h>
# include "constants.h"
# include "types.h"
# include "../../utils/utils.h"

typedef struct s_player
{
	t_obj	obj;
	int		collision;
	int		width;
	int		height;
	int		color;
	t_img	*sprite;
	int		x;
	int		y;
}   t_player;

void	create_player(t_win *window);

#endif
