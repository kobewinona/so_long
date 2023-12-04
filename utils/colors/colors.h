/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:04:03 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 17:04:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

int		generate_color(int alpha, int red, int green, int blue);
int		get_a(int argb);
int		get_r(int argb);
int		get_g(int argb);
int		get_b(int argb);

#endif
