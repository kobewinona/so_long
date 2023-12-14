/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_loger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:35:21 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/14 18:35:23 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "val_error_logger.h"

void log_validation_errors(t_val_info *val_info, t_list **error_log)
{
	if (val_info->is_rectangular == FALSE)
		val_info->is_valid = log_error_message(error_log, RECTANGULAR_ERR, FALSE);
	if (val_info->is_surrounded_with_walls == FALSE)
		val_info->is_valid = log_error_message(error_log, WALLS_SURROUNDED_ERR, FALSE);
	if (val_info->players_count != 1)
		val_info->is_valid = log_error_message(error_log, PLAYERS_COUNT_ERR, FALSE);
	if (val_info->collectables_count < 1)
		val_info->is_valid = log_error_message(error_log, COLLECTABLES_COUNT_ERR, FALSE);
	if (val_info->exits_count != 1)
		val_info->is_valid = log_error_message(error_log, EXITS_COUNT_ERR, FALSE);
	if (val_info->is_valid == TRUE)
	{
		if (val_info->is_solvable == FALSE)
			val_info->is_valid = log_error_message(error_log, SOLVABLE_ERR, FALSE);
	}
}
