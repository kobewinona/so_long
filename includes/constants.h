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
# define VALID_MAPFILE_EXT ".ber"

// magic numbers
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 2

// keyboard keys
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

// size
# define SPRITE_WIDTH 64
# define SPRITE_HEIGHT 64

// colors
# define RED "\033[31m"
# define GREY "\033[90m"
# define DARK_GREEN "\033[32m"
# define DARK_BLUE "\033[34m"
# define DARK_PURPLE "\033[35m"
# define DEFAULT "\033[0m"

// error messages
# define GAME_ERR "failed to start a game\n"
# define GAME_ENV_ERR "failed to create game environment\n"
# define UNKNOWN_ERR "unknown error occurred, please try again\n"

// map errors
# define NO_MAPFILE_ERR "no map provided\n"
# define TOO_MANY_ARGUMENTS_ERR "only a map must be provided\n"
# define READING_MAPFILE_ERR "failed to read map file\n"
# define MAPFILE_EXT_ERR "map file extension must be .ber\n"

// layout errors
# define LAYOUT_ERR "failed to create a layout\n"
# define TYPES_TABLE_ERR "failed to create a types table\n"
# define BUFFER_ERR "failed to create game buffer\n"
# define INVALID_OBJ_ERR "invalid map characters found\n"

// layout validation errors
# define VALIDATION_ERR "map is not valid\n"
# define RECTANGULAR_ERR "map is not rectangular\n"
# define WALLS_SURROUNDED_ERR "map must be surrounded with walls\n"
# define PLAYERS_COUNT_ERR "there must be 1 player\n"
# define COLLECTABLES_COUNT_ERR "there must be at least 1 collectable\n"
# define EXITS_COUNT_ERR "there must be 1 exit\n"
# define UNSOLVABLE_ERR "map must be solvable\n"

// window errors
# define WINDOW_ERR "failed to create a window\n"

// sprite errors
# define SPRITES_ERR "failed to create sprites\n"
# define SPRITE_ERR "failed to create a sprite\n"

#endif
