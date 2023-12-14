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

void    cleanup_game(void **ptr)
{
	t_gstate    *game;

	game = (t_gstate *)*ptr;
	if (game)
	{
		if (game->layout && game->layout->cleanup)
			game->layout->cleanup(&game->layout);
		free(game);
	}
}

int init_game(const char *mapfile, t_list **error_log)
{
	t_gstate    *game;

	game = (t_gstate *)malloc(sizeof(t_gstate));
	if (!game)
		return (print_error_message(UNKNOWN_ERR, ERROR));
	game->error_log = error_log;
	handle_error(create_layout(&game->layout, mapfile, game->error_log), &game, (t_error){
			&cleanup_game, GAME_ERR, game->error_log, TRUE});
	game->layout->print_buffer(game->layout, (t_xy){0, 0});
	cleanup_game((void **)&game);
	return (SUCCESS);
}
