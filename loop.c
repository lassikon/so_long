/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:55 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/14 13:16:17 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game);
}
