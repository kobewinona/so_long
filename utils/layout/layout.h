/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:46:24 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 14:46:26 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_H
#define LAYOUT_H
# include "so_long.h"
# include "../get_next_line/get_next_line.h"
# include "../print_error/print_error.h"

typedef struct s_layout {
    int     rows;
    int     columns;
    char    **grid;
}   t_layout;

t_layout   *create_layout(char *filename);

#endif
