/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:11 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 15:32:12 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_BUFFER_H
#define LAYOUT_BUFFER_H
# include "so_long.h"
# include "../types_table/types_table.h"

int init_layout_buffer(const char *mapfile, t_obj_type ***buffer, t_obj_type *types_table, t_list **error_log);

#endif
