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
# include "types.h"
# include <stdio.h>

typedef struct s_obj {
	t_obj_type	obj_type;
}	t_obj;

#endif
