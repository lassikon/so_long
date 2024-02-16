/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:26:53 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/16 15:52:18 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_array_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.array_copy[i] != NULL)
	{
		free(game->map.array_copy[i]);
		i++;
	}
	free(game->map.array_copy);
}

static bool	valid_path(char **array)
{
	int	y;
	int	x;

	y = 0;
	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			if (array[y][x] == 'C' || array[y][x] == 'E')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static void	fill(char **array, int x, int y)
{
	if (array[y][x] != '0' && array[y][x] != 'C' && array[y][x] != 'E')
		return ;
	array[y][x] = 'X';
	fill(array, x - 1, y);
	fill(array, x + 1, y);
	fill(array, x, y - 1);
	fill(array, x, y + 1);
}

void	check_path(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x / TILE;
	y = game->player_y / TILE;
	game->map.array_copy[y][x] = '0';
	fill(game->map.array_copy, x, y);
	if (valid_path(game->map.array_copy))
	{
		free_array_copy(game);
		return ;
	}
	else
	{
		free_array_copy(game);
		error_n_exit(game, "Map has no valid path");
	}
}
