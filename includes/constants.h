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
# define ERROR (-1)
# define SUCCESS 2

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
# define GAME_ERR "failed to start a game\n"
# define UNKNOWN_ERR "unknown error occurred, please try again\n"

// map errors
# define NO_MAP_ERR "no map provided\n"
# define TOO_MANY_ARGUMENTS_ERR "only a map must be provided\n"
# define READING_MAP_ERR "failed to read map file\n"
# define MAP_EXT_ERR "map file extension must be .ber\n"

// layout errors
# define LAYOUT_ERR "failed to create a layout\n"
# define TYPES_TABLE_ERR "failed to create a types table\n"
# define BUFFER_ERR "failed to create a layout buffer\n"
# define INVALID_OBJ_ERR "invalid map characters found\n"

// layout validation errors
# define LAYOUT_VALIDATION_ERR "map is not valid\n"
# define MAP_NOT_RECTANGULAR_ERR "map is not rectangular\n"
# define MAP_TOO_SMALL_ERR "map is too small\n"
# define WALLS_SURROUNDED_ERR "map must be surrounded with walls\n"
# define PLAYERS_COUNT_ERR "there must be 1 player on the map\n"
# define COLLECTABLES_COUNT_ERR "there must be at least 1 collectable on the map\n"
# define EXITS_COUNT_ERR "there must be 1 exit on the map\n"

#endif
