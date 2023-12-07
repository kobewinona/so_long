/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:53:03 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/01 14:53:04 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H
# include "./player/player.h"
# include "./ground/ground.h"
# include "./wall/wall.h"
# include "./collectable/collectable.h"

int	read_keys(int key_pressed, void *param);

#endif
