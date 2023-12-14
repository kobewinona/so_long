/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_validator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:47:12 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/12 15:47:13 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_VALIDATOR_H
#define LAYOUT_VALIDATOR_H
# include "../layout_buffer/layout_buffer.h"
# include "../types_table/types_table.h"

typedef struct s_val_info {
	int is_valid;
	int is_rectangular;
	int is_surrounded_with_walls;
	int players_count;
	int collectables_count;
	int exits_count;
	int is_solvable;
	int rows;
	int columns;
}   t_val_info;

int     is_layout_valid(const t_obj_type *const *buffer, t_list **error_log);
void    log_validation_errors(t_val_info *val_info, t_list **error_log);
int     is_layout_solvable(const t_obj_type *const *buffer, t_val_info *val_info, t_list **error_log);

#endif