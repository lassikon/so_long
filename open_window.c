/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:15 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/22 14:57:08 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			if (game->map.arr[y][x] != '1')
			{
				if (mlx_image_to_window(game->mlx, game->img.floor, \
					x * TILE, y * TILE) == -1)
					mlx42_error(game, mlx_strerror(mlx_errno));
			}
			x++;
		}
		x = 0;
		y++;
	}
}

static void	player_images_to_window(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (mlx_image_to_window(game->mlx, game->img.pl_d[i], x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.pl_d[i]->instances[0].enabled = false;
		if (mlx_image_to_window(game->mlx, game->img.pl_u[i], x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.pl_u[i]->instances[0].enabled = false;
		if (mlx_image_to_window(game->mlx, game->img.pl_l[i], x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.pl_l[i]->instances[0].enabled = false;
		if (mlx_image_to_window(game->mlx, game->img.pl_r[i], x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.pl_r[i]->instances[0].enabled = false;
		i++;
	}
	game->img.pl_d[0]->instances[0].enabled = true;
}

static void	draw_tile(t_game *game, int x, int y)
{
	if (game->map.arr[y / TILE][x / TILE] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->img.wall, x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.arr[y / TILE][x / TILE] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->img.coll, x + D, y + D) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.arr[y / TILE][x / TILE] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->img.wall, x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		if (mlx_image_to_window(game->mlx, game->img.exit, x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		if (mlx_image_to_window(game->mlx, game->img.open_exit, x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.open_exit->instances[0].enabled = false;
	}
	else if (game->map.arr[y / TILE][x / TILE] == 'P')
		player_images_to_window(game, x, y);
	else if (game->map.arr[y / TILE][x / TILE] == 'X')
		add_monster(game, x, y);
}

static void	images_to_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	draw_background(game);
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	open_window(t_game *game)
{
	int	center;

	center = game->map.width * TILE / 2;
	game->mlx = mlx_init(game->win_width, game->win_height, "so_long", true);
	if (!game->mlx)
		mlx42_error(game, mlx_strerror(mlx_errno));
	load_textures(game);
	textures_to_images(game);
	images_to_window(game);
	mlx_put_string(game->mlx, "Moves:", center - 48, 10);
}
