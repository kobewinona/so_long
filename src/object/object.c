/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:35:54 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/27 18:35:54 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	cleanup_object(t_obj *obj)
{
	free(obj);
}

t_obj	*get_object(t_list *node)
{
	return ((t_obj *)node->content);
}

t_obj	*create_object(t_obj_type type)
{
	t_obj	*obj;

	obj = malloc(sizeof(t_obj));
	if (obj)
		obj->type = type;
	return (obj);
}