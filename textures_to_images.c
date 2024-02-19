/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:33:07 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 16:37:48 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_up_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->images.player_up[i] = mlx_texture_to_image(game->mlx, game->textures.playup_tex[i]);
		if (!game->images.player_up[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->textures.playup_tex[i]);
		i++;
	}
}

static void	player_down_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->images.player_down[i] = mlx_texture_to_image(game->mlx, game->textures.playdown_tex[i]);
		if (!game->images.player_down[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->textures.playdown_tex[i]);
		i++;
	}
}

static void	player_left_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->images.player_left[i] = mlx_texture_to_image(game->mlx, game->textures.playleft_tex[i]);
		if (!game->images.player_left[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->textures.playleft_tex[i]);
		i++;
	}
}

static void	player_right_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->images.player_right[i] = mlx_texture_to_image(game->mlx, game->textures.playright_tex[i]);
		if (!game->images.player_right[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->textures.playright_tex[i]);
		i++;
	}
}

void	textures_to_images(t_game *game)
{
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall_tex);
	if (!game->images.wall)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->textures.wall_tex);
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor_tex);
	if (!game->images.floor)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->textures.floor_tex);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit_tex);
	if (!game->images.exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->textures.exit_tex);
	game->images.coll = mlx_texture_to_image(game->mlx, game->textures.coll_tex);
	if (!game->images.coll)
		mlx42_error(game, mlx_strerror(mlx_errno));
	mlx_delete_texture(game->textures.coll_tex);
	player_up_textures_to_images(game);
	player_down_textures_to_images(game);
	player_left_textures_to_images(game);
	player_right_textures_to_images(game);
}
