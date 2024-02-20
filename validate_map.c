/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:58:47 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 16:51:59 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.arr[0][i] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		if (game->map.arr[game->map.height - 1][i] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.arr[i][0] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		if (game->map.arr[i][game->map.width - 1] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		i++;
	}
}

static void	check_chars(t_game *game, int i, int j)
{
	if (game->map.arr[i][j] == '1' || game->map.arr[i][j] == '0')
		return ;
	else if (game->map.arr[i][j] == 'P')
	{
		game->map.player += 1;
		game->player_x = j * TILE + D;
		game->player_y = i * TILE + D;
		return ;
	}
	else if (game->map.arr[i][j] == 'C')
	{
		game->map.colls_at_start += 1;
		return ;
	}
	else if (game->map.arr[i][j] == 'E')
	{
		game->map.exit += 1;
		return ;
	}
	else
		error_n_exit(game, "Invalid character in map");
}

static void	validate_chars(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.height - 1)
	{
		j = 1;
		while (j < game->map.width - 1)
		{
			check_chars(game, i, j);
			j++;
		}
		i++;
	}
}

static void	check_components(t_game *game)
{
	if (game->map.player > 1)
		error_n_exit(game, "Map has too many players");
	if (game->map.player < 1)
		error_n_exit(game, "Map has no player");
	if (game->map.exit > 1)
		error_n_exit(game, "Map has too many exits");
	if (game->map.exit < 1)
		error_n_exit(game, "Map has no exit");
	if (game->map.colls_at_start < 1)
		error_n_exit(game, "Map has no collectibles");
}

void	validate_map(t_game *game)
{
	if (game->map.width < 3 || game->map.height < 3)
		error_n_exit(game, "Map is too small");
	check_walls(game);
	validate_chars(game);
	check_components(game);
	check_path(game);
	game->colls = game->map.colls_at_start;
}
