/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:59:43 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/08 17:59:44 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// title
# define TITLE "so_long"

// map extension
# define VALID_MAP_EXT ".ber"

// magic numbers
# define TRUE 1
# define FALSE 0
# define ERROR -1

// keyboard keys
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// grid size
// TODO adjust TILE_WIDTH and TILE_HEIGHT to resolution
// TODO rename tiles to something more generic
# define WINDOW_WIDTH 768
# define WINDOW_HEIGHT 585
# define TILE_WIDTH 64
# define TILE_HEIGHT 64

// colors
# define RED "\033[31m"
# define GREY "\033[90m"
# define DEFAULT "\033[0m"

// error messages
# define UNKNOWN_ERR "> unknown error occurred\n"
# define NO_MAP_ERR "> no map provided\n"
# define TOO_MANY_ARGUMENTS_ERR "> too many arguments provided\n"
# define INCORRECT_MAP_EXT_ERR "> map file extension must be .ber\n"
# define LAYOUT_TOO_SMALL_ERR "> map is too small\n"

#endif
