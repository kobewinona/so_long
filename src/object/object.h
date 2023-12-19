/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:06:31 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/07 16:06:31 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "so_long.h"
# include "gdata.h"

typedef struct s_obj	t_obj;

struct s_obj
{
	t_obj_type	type;
	t_win		*win;
	t_img		*sprite;
	int			collision;
	t_xy		pos;
	void		(*render)(t_obj);
};

t_obj	create_object(t_gdata gdata, t_obj_type type, t_xy pos);
void	render_object(t_obj obj);

#endif