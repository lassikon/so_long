/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 15:49:35 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_array(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->tex.down[i] = NULL;
		game->img.pl_d[i] = NULL;
		game->tex.up[i] = NULL;
		game->img.pl_u[i] = NULL;
		game->tex.left[i] = NULL;
		game->img.pl_l[i] = NULL;
		game->tex.righ[i] = NULL;
		game->img.pl_r[i] = NULL;
		i++;
	}
}

static void	init_struct(t_game *game)
{
	game->map.arr = NULL;
	game->map.array_copy = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.fd = -1;
	game->map.colls_at_start = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->mlx = NULL;
	game->tex.wall = NULL;
	game->tex.floor = NULL;
	game->tex.exit = NULL;
	game->tex.coll = NULL;
	game->img.wall = NULL;
	game->img.floor = NULL;
	game->img.exit = NULL;
	game->img.open_exit = NULL;
	game->img.coll = NULL;
	game->img.moves = NULL;
	game->colls = 0;
	game->steps = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->prev_direction = 0;
	init_player_array(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game);
	if (argc != 2)
		error_n_exit(&game, "Invalid number of arguments");
	get_map(&game, argv[1]);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	open_window(&game);
	mlx_loop_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_memory(&game);
	return (0);
}
