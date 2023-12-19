/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdata.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:36:56 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/19 16:36:57 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDATA_H
# define GDATA_H
# include "../utils/utils.h"

typedef struct s_gdata
{
	t_win		*window;
	t_list		**error_log;
	t_obj_type	*types_table;
	t_img		**sprites;
}	t_gdata;

#endif
