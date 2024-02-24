/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:46:20 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/24 10:50:39 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.arr != NULL)
	{
		while (game->map.arr[i] != NULL)
		{
			free(game->map.arr[i]);
			i++;
		}
		free(game->map.arr);
	}
}

static void	free_monster_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < MONSTER_FRAMES)
	{
		if (game->tex.mons[i])
			mlx_delete_texture(game->tex.mons[i]);
		i++;
	}
}

static void	free_player_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (game->tex.up[i])
			mlx_delete_texture(game->tex.up[i]);
		if (game->tex.down[i])
			mlx_delete_texture(game->tex.down[i]);
		if (game->tex.left[i])
			mlx_delete_texture(game->tex.left[i]);
		if (game->tex.righ[i])
			mlx_delete_texture(game->tex.righ[i]);
		i++;
	}
}

void	free_textures(t_game *game)
{
	free_monster_textures(game);
	free_player_textures(game);
	if (game->tex.wall)
		mlx_delete_texture(game->tex.wall);
	if (game->tex.floor)
		mlx_delete_texture(game->tex.floor);
	if (game->tex.exit)
		mlx_delete_texture(game->tex.exit);
	if (game->tex.open_exit)
		mlx_delete_texture(game->tex.open_exit);
	if (game->tex.coll)
		mlx_delete_texture(game->tex.coll);
}
