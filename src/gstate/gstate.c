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

int init_game(char *map, t_list **error_log)
{
	t_gstate    *game;

	game = (t_gstate *)malloc(sizeof(t_gstate));
	if (!game)
		return (print_error_message(UNKNOWN_ERR, TRUE));
	game->error_log = error_log;
	handle_error(create_layout(&game->layout, map, game->error_log), &game, (t_error){
			&cleanup_game, GAME_ERR, game->error_log, TRUE});
//	game.window = create_window();
//	if (!game.window.mlx_ptr || !game.window.win_ptr)
//        handle_error(&game, UNKNOWN_ERR);
//	game.ground = create_ground(game.window);
//	mlx_loop(game.window.mlx_ptr);
	cleanup_game((void **)&game);
	return (SUCCESS);
}
