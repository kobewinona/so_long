/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:48:35 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/28 00:48:37 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

void	add_frame(t_win window, t_animation *animation, t_sprite sprite, t_sprite_slice sprite_slice)
{
	t_img	*frame;
	int		i;
	int		j;

	frame = (t_img *)calloc(sizeof(t_img), 1);
	if (!frame)
		return ;
	frame = create_image(sprite_slice.width, sprite_slice.height, window.mlx_ptr);
	i = 0;
	while (i < sprite_slice.width)
	{
		j = 0;
		while (j < sprite_slice.height)
		{
//			put_pixel_img(*frame, sprite_slice.width - j, i, get_pixel_img(sprite.sprite_img, sprite_slice.x + j, sprite_slice.y + i));
			put_pixel_img(*frame, j, i, get_pixel_img(sprite.sprite_img, (sprite_slice.x + j), (sprite_slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&animation->frames, ft_lstnew(frame));
}