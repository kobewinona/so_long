/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:33:52 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/11 12:33:53 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H
# include "so_long.h"

void    parse_map(char **argv, t_obj_type ***buffer);
int     count_rows(char **argv);

#endif
