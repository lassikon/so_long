/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:25:35 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 13:13:45 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_playup_textures(t_game *game)
{
	game->tex.up[0] = mlx_load_png(PLAYER_UP1);
	if (!game->tex.up[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.up[1] = mlx_load_png(PLAYER_UP2);
	if (!game->tex.up[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.up[2] = mlx_load_png(PLAYER_UP3);
	if (!game->tex.up[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playdown_textures(t_game *game)
{
	game->tex.down[0] = mlx_load_png(PLAYER_DOWN1);
	if (!game->tex.down[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.down[1] = mlx_load_png(PLAYER_DOWN2);
	if (!game->tex.down[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.down[2] = mlx_load_png(PLAYER_DOWN3);
	if (!game->tex.down[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playleft_textures(t_game *game)
{
	game->tex.left[0] = mlx_load_png(PLAYER_LEFT1);
	if (!game->tex.left[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.left[1] = mlx_load_png(PLAYER_LEFT2);
	if (!game->tex.left[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.left[2] = mlx_load_png(PLAYER_LEFT3);
	if (!game->tex.left[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playright_textures(t_game *game)
{
	game->tex.righ[0] = mlx_load_png(PLAYER_RIGHT1);
	if (!game->tex.righ[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.righ[1] = mlx_load_png(PLAYER_RIGHT2);
	if (!game->tex.righ[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.righ[2] = mlx_load_png(PLAYER_RIGHT3);
	if (!game->tex.righ[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

void	load_textures(t_game *game)
{
	game->tex.wall = mlx_load_png(WALL_IMG);
	if (!game->tex.wall)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.floor = mlx_load_png(FLOOR_IMG);
	if (!game->tex.floor)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.exit = mlx_load_png(EXIT_IMG);
	if (!game->tex.exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.open_exit = mlx_load_png(OPEN_EXIT_IMG);
	if (!game->tex.open_exit)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->tex.coll = mlx_load_png(COLL_IMG);
	if (!game->tex.coll)
		mlx42_error(game, mlx_strerror(mlx_errno));
	load_playup_textures(game);
	load_playdown_textures(game);
	load_playleft_textures(game);
	load_playright_textures(game);
}
