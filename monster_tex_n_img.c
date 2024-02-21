/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_tex_n_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:04:56 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 13:18:38 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_monster_texture(t_game *game)
{
	game->tex.mons[0] = mlx_load_png(MONSTER1);
	if (!game->tex.mons[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[1] = mlx_load_png(MONSTER2);
	if (!game->tex.mons[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[2] = mlx_load_png(MONSTER3);
	if (!game->tex.mons[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[3] = mlx_load_png(MONSTER4);
	if (!game->tex.mons[3])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[4] = mlx_load_png(MONSTER5);
	if (!game->tex.mons[4])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[5] = mlx_load_png(MONSTER6);
	if (!game->tex.mons[5])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[6] = mlx_load_png(MONSTER7);
	if (!game->tex.mons[6])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.mons[7] = mlx_load_png(MONSTER8);
	if (!game->tex.mons[7])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	monster_textures_to_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < MONSTER_FRAMES)
	{
		game->img.mons[i] = mlx_texture_to_image(game->mlx, game->tex.mons[i]);
		if (!game->img.mons[i])
			mlx42_error(game, mlx_strerror(mlx_errno));
		mlx_delete_texture(game->tex.mons[i]);
		i++;
	}
}

static void	monster_images_to_window(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < MONSTER_FRAMES)
	{
		if (mlx_image_to_window(game->mlx, game->img.mons[i], x, y) == -1)
			mlx42_error(game, mlx_strerror(mlx_errno));
		game->img.mons[i]->instances[0].enabled = false;
		i++;
	}
	game->img.mons[0]->instances[0].enabled = true;
}

void	add_monster(t_game *game, int x, int y)
{
	load_monster_texture(game);
	monster_textures_to_images(game);
	monster_images_to_window(game, x, y);
}
