/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gstate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklimkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:06:17 by dklimkin          #+#    #+#             */
/*   Updated: 2023/12/08 15:06:18 by dklimkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gstate.h"

static void handle_error(t_gstate *game)
{
    int y;

    if (game->buffer)
    {
        y = 0;
        while (game->buffer[y])
        {
            free(game->buffer[y]);
            y++;
        }
        free(game->buffer);
    }
}

void	render_buffer(t_gstate	*game)
{
    int	rows;
    int	columns;
    int	x;
    int	y;

    rows = WINDOW_HEIGHT / TILE_HEIGHT;
    columns = WINDOW_WIDTH / TILE_WIDTH;
    y = 0;
    while (y < rows)
    {
        x = 0;
        while (x < columns)
        {
            if (game->buffer[y][x] == GROUND)
                game->ground->render_ground(x, y, game->ground);
            x++;
        }
        y++;
    }
}

void	init_buffer(t_gstate *game)
{
    int	rows;
    int	columns;
    int	x;
    int	y;

    rows = WINDOW_HEIGHT / TILE_HEIGHT;
    columns = WINDOW_WIDTH / TILE_WIDTH;
    game->buffer = malloc((rows * sizeof(t_obj_type *)));
    if (!game->buffer)
        return (handle_error(game));
    y = 0;
    while (y < rows)
    {
        game->buffer[y] = malloc((columns * sizeof(t_obj_type)));
        if (!game->buffer[y])
            return (handle_error(game));
        x = 0;
        while (x < columns)
        {
            game->buffer[y][x] = EMPTY;
            x++;
        }
        y++;
    }
}
