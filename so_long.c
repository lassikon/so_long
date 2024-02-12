/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/12 20:36:15 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_struct(t_game *game)
{
	game->map.array = NULL;
	game->map.width = 0;
	game->map.height = 0;
	game->map.fd = -1;
	game->map.collectibles = 0;
	game->map.player = 0;
	game->map.exit = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	// mlx_t *mlx;

	init_struct(&game);
	if (argc != 2)
		error_n_exit(&game, "Error\nInvalid number of arguments");
	get_map(&game, argv[1]);
	/* mlx = mlx_init(256, 256, "so_long", true);
	if (!mlx)
		mlx_error(&game, mlx_strerror(mlx_errno)); */
	free_memory(&game);
	return (0);
}
