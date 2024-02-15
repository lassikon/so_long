/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/15 16:33:46 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_game *game)
{
	game->map.array = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.fd = -1;
	game->map.colls_at_start = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->mlx = NULL;
	game->textures.wall_tex = NULL;
	game->textures.floor_tex = NULL;
	game->textures.player_tex = NULL;
	game->textures.coll_tex = NULL;
	game->textures.exit_tex = NULL;
	game->images.wall = NULL;
	game->images.floor = NULL;
	game->images.player = NULL;
	game->images.exit = NULL;
	game->images.coll = NULL;
	game->colls = 0;
	game->steps = 0;
	game->player_x = 0;
	game->player_y = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game);
	if (argc != 2)
		error_n_exit(&game, "Error\nInvalid number of arguments");
	get_map(&game, argv[1]);
	open_window(&game);
	mlx_loop_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_memory(&game);
	return (0);
}
