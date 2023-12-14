/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodandfill.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:16:56 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/14 13:17:30 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOODANDFILL_H
# define FLOODANDFILL_H

# include <stdbool.h>
# include "so_long.h"
# include "layout_validator.h"
# include <stdio.h>

typedef struct s_ff
{
	bool	**buffer;
	int		players_x;
	int		players_y;
	int		collectables_count;
	int		is_exit_found;
}	t_ff;

#endif
