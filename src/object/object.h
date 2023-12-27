/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:36:01 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/27 18:36:07 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "so_long.h"

typedef struct s_obj
{
	t_obj_type	type;
}	t_obj;

t_obj	*create_object(t_obj_type type);
t_obj	*get_object(t_list *node);
void	cleanup_object(t_obj *obj);

#endif
