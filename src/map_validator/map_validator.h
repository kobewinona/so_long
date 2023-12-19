/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:39 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/18 12:14:40 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H
# include "so_long.h"
# include "../object/object.h"

typedef struct s_val_info
{
	int	is_valid;
	int	is_rectangular;
	int	is_surrounded_with_walls;
	int	players_count;
	int	collectables_count;
	int	exits_count;
	int	is_solvable;
	int	height;
	int	width;
}	t_val_info;

typedef struct s_ff
{
	bool	**buffer;
	int		players_x;
	int		players_y;
	int		collectables_count;
	int		is_exit_found;
}	t_ff;

int		is_map_valid(t_obj **buffer, t_list **error_log);
int		is_map_solvable(
			t_obj **buffer, t_val_info *val_info, t_list **error_log);
void	log_validation_errors(t_val_info *val_info, t_list **error_log);

#endif
