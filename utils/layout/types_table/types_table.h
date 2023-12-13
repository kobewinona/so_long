/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:06:31 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 11:06:32 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_TABLE_H
#define TYPES_TABLE_H
# include "so_long.h"

int         create_types_table(t_obj_type **types_table, t_list **error_log);
t_obj_type  match_type(const t_obj_type *table, int src);
int         is_type_valid(const t_obj_type *types_table, t_obj_type src);

#endif
