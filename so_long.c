/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 15:08:56 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_character_images_n_textures(t_game *game)
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
	i = 0;
	while (i < MONSTER_FRAMES)
	{
		game->tex.mons[i] = NULL;
		game->img.mons[i] = NULL;
		i++;
	}
}

static void	init_tile_images_n_textures(t_game *game)
{
	game->tex.wall = NULL;
	game->img.wall = NULL;
	game->tex.floor = NULL;
	game->img.floor = NULL;
	game->tex.exit = NULL;
	game->img.exit = NULL;
	game->img.open_exit = NULL;
	game->tex.coll = NULL;
	game->img.coll = NULL;
	game->img.moves = NULL;
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
	game->colls = 0;
	game->steps = 0;
	game->monster = false;
	game->mons_x = 0;
	game->mons_y = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->prev_direction = 0;
	game->over = false;
	game->eaten_by_monster = false;
	game->exit_reached = false;
	init_tile_images_n_textures(game);
	init_character_images_n_textures(game);
}

static void	check_args(t_game *game, int argc, char **argv)
{
	char	*file_type;

	if (argc != 2)
		error_n_exit(game, "Invalid number of arguments");
	file_type = ft_strrchr(argv[1], '.');
	if (file_type == NULL || ft_strncmp(file_type, ".ber", 5) != 0)
		error_n_exit(game, "Invalid map file");
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game);
	check_args(&game, argc, argv);
	get_map(&game, argv[1]);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	open_window(&game);
	mlx_loop_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_memory(&game);
	return (0);
}
