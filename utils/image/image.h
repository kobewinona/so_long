/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:55:49 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:55:50 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_img
{
	t_win			win;
	void			*img_ptr;
	char			*addr;
	unsigned int	width;
	unsigned int	height;
	int				bpp;
	int				endian;
	int				line_len;
}					t_img;

t_img	generate_image(int width, int height, t_win window);

#endif
