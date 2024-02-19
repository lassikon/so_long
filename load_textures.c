/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:25:35 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:13 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_playup_textures(t_game *game)
{
	game->textures.playup_tex[0] = mlx_load_png(PLAYER_UP1);
	if (!game->textures.playup_tex[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playup_tex[1] = mlx_load_png(PLAYER_UP2);
	if (!game->textures.playup_tex[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playup_tex[2] = mlx_load_png(PLAYER_UP3);
	if (!game->textures.playup_tex[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playdown_textures(t_game *game)
{
	game->textures.playdown_tex[0] = mlx_load_png(PLAYER_DOWN1);
	if (!game->textures.playdown_tex[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playdown_tex[1] = mlx_load_png(PLAYER_DOWN2);
	if (!game->textures.playdown_tex[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playdown_tex[2] = mlx_load_png(PLAYER_DOWN3);
	if (!game->textures.playdown_tex[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playleft_textures(t_game *game)
{
	game->textures.playleft_tex[0] = mlx_load_png(PLAYER_LEFT1);
	if (!game->textures.playleft_tex[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playleft_tex[1] = mlx_load_png(PLAYER_LEFT2);
	if (!game->textures.playleft_tex[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playleft_tex[2] = mlx_load_png(PLAYER_LEFT3);
	if (!game->textures.playleft_tex[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

static void	load_playright_textures(t_game *game)
{
	game->textures.playright_tex[0] = mlx_load_png(PLAYER_RIGHT1);
	if (!game->textures.playright_tex[0])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playright_tex[1] = mlx_load_png(PLAYER_RIGHT2);
	if (!game->textures.playright_tex[1])
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.playright_tex[2] = mlx_load_png(PLAYER_RIGHT3);
	if (!game->textures.playright_tex[2])
		mlx42_error(game, mlx_strerror(mlx_errno));
}

void	load_textures(t_game *game)
{
	game->textures.wall_tex = mlx_load_png(WALL_IMG);
	if (!game->textures.wall_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.floor_tex = mlx_load_png(FLOOR_IMG);
	if (!game->textures.floor_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.exit_tex = mlx_load_png(EXIT_IMG);
	if (!game->textures.exit_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	game->textures.coll_tex = mlx_load_png(COLL_IMG);
	if (!game->textures.coll_tex)
		mlx42_error(game, mlx_strerror(mlx_errno));
	load_playup_textures(game);
	load_playdown_textures(game);
	load_playleft_textures(game);
	load_playright_textures(game);
}