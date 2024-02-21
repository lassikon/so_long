/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:55 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 17:06:51 by lkonttin         ###   ########.fr       */
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
	char		*str;
	int			center;
	static int	moves = 0;

	center = game->map.width * TILE / 2;
	if (game->steps != moves)
	{
		if (game->img.moves)
			mlx_delete_image(game->mlx, game->img.moves);
		str = ft_itoa(game->steps);
		game->img.moves = mlx_put_string(game->mlx, str, center + 24, 10);
		if (!game->img.moves)
			mlx42_error(game, mlx_strerror(mlx_errno));
		free(str);
		moves = game->steps;
	}
}

static void	check_game_status(t_game *game)
{
	int	x_center;
	int	y_center;

	x_center = game->map.width * TILE / 2 - 96;
	y_center = game->map.height * TILE / 2 - 24;
	if (game->over)
	{
		if (game->exit_reached)
			mlx_put_string(game->mlx, "You won!", x_center, y_center);
		else
			mlx_put_string(game->mlx, "You lost!", x_center, y_center);
		mlx_put_string(game->mlx, "Press ESC to exit", x_center, y_center + 24);
		disable_player_frames(game);
	}
}

void	handle_monster(t_game *game)
{
	if (game->monster)
	{
		animate_monster(game);
		move_monster(game);
	}
}

void	keyhook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_game_status(game);
	display_moves(game);
	handle_monster(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && !game->over)
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) && !game->over)
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && !game->over)
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) && !game->over)
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && !game->over)
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP) && !game->over)
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && !game->over)
		move_down(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) && !game->over)
		move_down(game);
}
