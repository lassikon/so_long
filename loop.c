/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:55 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 16:51:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	if (str == NULL)
		error_n_exit(game, "Memory allocation failed");
	ft_putstr_fd("Moves: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

static void	display_moves(t_game *game)
{
	char	*str;
	int		center;
	int		old_moves;

	center = game->map.width * TILE / 2 - 20;
	old_moves = 0;
	if (game->steps != old_moves)
	{
		if (game->img.moves)
			mlx_delete_image(game->mlx, game->img.moves);
		str = ft_itoa(game->steps);
		game->img.moves = mlx_put_string(game->mlx, str, center, 10);
		if (!game->img.moves)
			mlx42_error(game, mlx_strerror(mlx_errno));
		free(str);
		old_moves = game->steps;
	}
}

void	keyhook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	display_moves(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_down(game);
}
