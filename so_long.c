/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:04 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/24 10:47:37 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free_array(&game);
	return (0);
}
