/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:55 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 16:48:26 by lkonttin         ###   ########.fr       */
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



/* void	animate_colls(void *param)
{
	t_game		*game;
	static int	i = 0;
	static int	counter = 0;
	int			k;
	int			j;

	game = (t_game *)param;
	k = 0;
	if (counter == COLL_ANIMATION_SPEED)
	{
		j = i;
		while (k < game->map.colls_at_start)
		{
			game->images.coll[j]->instances[k].enabled = false;
			j++;
			if (j == COLL_FRAMES)
				j = 0;
			game->images.coll[j]->instances[k].enabled = true;
			k++;
		}
		i++;
		if (i == COLL_FRAMES)
			i = 0;
		counter = 0;
	}
	counter++;
} */
