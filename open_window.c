/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:00:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/13 13:22:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_textures(t_game *game)
{
	game->textures.wall_tex = mlx_load_png(WALL);
	if (!game->textures.wall_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.floor_tex = mlx_load_png(FLOOR);
	if (!game->textures.floor_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.player_tex = mlx_load_png(PLAYER);
	if (!game->textures.player_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.coll_tex = mlx_load_png(COLLECTIBLE);
	if (!game->textures.coll_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.exit_tex = mlx_load_png(EXIT);
	if (!game->textures.exit_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	textures_to_images(t_game *game)
{
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall_tex);
	if (!game->images.wall)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor_tex);
	if (!game->images.floor)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->images.player = mlx_texture_to_image(game->mlx, game->textures.player_tex);
	if (!game->images.player)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit_tex);
	if (!game->images.exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->images.coll = mlx_texture_to_image(game->mlx, game->textures.coll_tex);
	
}

static void	draw_background(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->win_height)
	{
		while (x < game->win_width)
		{
			if (mlx_image_to_window(game->mlx, game->images.floor, x * 32, y * 32) == -1)
				mlx42_error(game, mlx_strerror(mlx_errno));
			x++;
		}
		x = 0;
		y++;
	}
}

static void	draw_tile(t_game *game, int x, int y)
{
	if (game->map.array[y][x] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->images.wall, x * 32, y * 32) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.array[y][x] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->images.player, x * 32, y * 32) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.array[y][x] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->images.coll, x * 32, y * 32) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
	else if (game->map.array[y][x] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->images.exit, x * 32, y * 32) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
	}
}

static void	images_to_window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_background(game);
	while (y < game->map.height)
	{
		while (x < game->map.width)
		{
			draw_tile(game, x, y);
			x++;
		}
		x = 0;
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