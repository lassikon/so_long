/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:58:47 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/12 20:38:16 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.array[0][i] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		if (game->map.array[game->map.height - 1][i] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.array[i][0] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		if (game->map.array[i][game->map.width - 1] != '1')
			error_n_exit(game, "Map is not surrounded by walls");
		i++;
	}
}

static void	check_chars(t_game *game, int i, int j)
{
	if (game->map.array[i][j] == '1' || game->map.array[i][j] == '0')
		return ;
	else if (game->map.array[i][j] == 'P')
	{
		game->map.player += 1;
		return ;
	}
	else if (game->map.array[i][j] == 'C')
	{
		game->map.collectibles += 1;
		return ;
	}
	else if (game->map.array[i][j] == 'E')
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
	if (game->map.collectibles < 1)
		error_n_exit(game, "Map has no collectibles");
}

void	validate_map(t_game *game)
{
	if (game->map.width < 3 || game->map.height < 3)
		error_n_exit(game, "Map is too small");
	check_walls(game);
	validate_chars(game);
	check_components(game);
}