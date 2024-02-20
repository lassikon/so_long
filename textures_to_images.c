/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:07 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 15:16:51 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_up_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->img.pl_u[i] = mlx_texture_to_image(game->mlx, game->tex.up[i]);
		if (!game->img.pl_u[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->tex.up[i]);
		i++;
	}
}

static void	player_down_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->img.pl_d[i] = mlx_texture_to_image(game->mlx, game->tex.down[i]);
		if (!game->img.pl_d[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->tex.down[i]);
		i++;
	}
}

static void	player_left_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->img.pl_l[i] = mlx_texture_to_image(game->mlx, game->tex.left[i]);
		if (!game->img.pl_l[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->tex.left[i]);
		i++;
	}
}

static void	player_right_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->img.pl_r[i] = mlx_texture_to_image(game->mlx, game->tex.righ[i]);
		if (!game->img.pl_r[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->tex.righ[i]);
		i++;
	}
}

void	textures_to_images(t_game *game)
{
	game->img.wall = mlx_texture_to_image(game->mlx, game->tex.wall);
	if (!game->img.wall)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->tex.wall);
	game->img.floor = mlx_texture_to_image(game->mlx, game->tex.floor);
	if (!game->img.floor)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->tex.floor);
	game->img.exit = mlx_texture_to_image(game->mlx, game->tex.exit);
	if (!game->img.exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->tex.exit);
	game->img.open_exit = mlx_texture_to_image(game->mlx, game->tex.open_exit);
	if (!game->img.open_exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->tex.open_exit);
	game->img.coll = mlx_texture_to_image(game->mlx, game->tex.coll);
	if (!game->img.coll)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->tex.coll);
	player_up_textures_to_images(game);
	player_down_textures_to_images(game);
	player_left_textures_to_images(game);
	player_right_textures_to_images(game);
}
