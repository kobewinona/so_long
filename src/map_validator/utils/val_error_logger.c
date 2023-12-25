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

#include "../map_validator.h"

int	log_validation_errors(t_vdata vdata, t_list **error_log)
{
	if (vdata.is_rectangular == FALSE)
		vdata.is_valid = log_error_message(
				error_log, RECTANGULAR_ERR, FALSE);
	if (vdata.is_surrounded_with_walls == FALSE)
		vdata.is_valid = log_error_message(
				error_log, WALLS_SURROUNDED_ERR, FALSE);
	if (vdata.players_count != 1)
		vdata.is_valid = log_error_message(
				error_log, PLAYERS_COUNT_ERR, FALSE);
	if (vdata.collectables_count < 1)
		vdata.is_valid = log_error_message(
				error_log, COLLECTABLES_COUNT_ERR, FALSE);
	if (vdata.exits_count != 1)
		vdata.is_valid = log_error_message(
				error_log, EXITS_COUNT_ERR, FALSE);
	if (vdata.is_valid == TRUE)
	{
		if (vdata.is_solvable == FALSE)
			vdata.is_valid = log_error_message(
					error_log, UNSOLVABLE_ERR, FALSE);
	}
	return (vdata.is_valid);
}
