/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:17:15 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 16:41:09 by lkonttin         ###   ########.fr       */
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
			if (game->map.array[y][x] != '1')
			{
				if (mlx_image_to_window(game->mlx, game->images.floor, x * TILE, y * TILE) == -1)
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
		if (mlx_image_to_window(game->mlx, game->images.player_down[i], x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->images.player_down[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (mlx_image_to_window(game->mlx, game->images.player_up[i], x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->images.player_up[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (mlx_image_to_window(game->mlx, game->images.player_left[i], x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->images.player_left[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (mlx_image_to_window(game->mlx, game->images.player_right[i], x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->images.player_right[i]->instances[0].enabled = false;
		i++;
	}
	game->images.player_down[0]->instances[0].enabled = true;
}

static void	draw_tile(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->images.wall, x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.array[y][x] == 'P')
	{
		player_images_to_window(game, x, y);
	}
	else if (game->map.array[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->images.coll, x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.array[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->images.exit, x * TILE, y * TILE) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
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
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	open_window(t_game *game)
{
	game->mlx = mlx_init(game->win_width, game->win_height, "so_long", true);
	if (!game->mlx)
		mlx42_error(game, mlx_strerror(mlx_errno));;
	load_textures(game);
	textures_to_images(game);
	images_to_window(game);
}
