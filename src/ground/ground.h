/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:19:44 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 16:19:45 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_H
# define GROUND_H
# include "constants.h"
# include "types.h"
# include "../../utils/utils.h"

typedef struct s_ground t_ground;

struct s_ground {
	t_obj	obj;
    t_win   window;
	int		collision;
	int		width;
	int		height;
	int		color;
	t_img	*sprite;
	int		x;
	int		y;
	void	(*render_ground)(int, int, t_ground *);
};

t_ground	*create_ground(t_win window);
void		render_ground(int x, int y, t_ground *ground);

#endif
