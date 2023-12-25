/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:40:44 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 17:40:45 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_HANDLER_H
# define BUFFER_HANDLER_H
# include "so_long.h"
# include "../object/object.h"

void	print_types_buffer(t_obj_type **buffer, t_xy pos);
void	print_objects_buffer(t_obj **buffer, t_xy pos);
void	cleanup_types_buffer(t_obj_type **buffer);
void	cleanup_objs_buffer(t_obj **buffer);

#endif