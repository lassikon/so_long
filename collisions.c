/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:12:16 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/16 17:47:34 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_collision(t_game *game, int x, int y, int direction)
{
	if (direction == LEFT)
	{
		if (game->map.array[y / TILE][x / TILE] == '1'
			|| game->map.array[(y + PLAYER - 1) / TILE][x / TILE] == '1')
			return (true);
	}
	else if (direction == RIGHT)
	{
		if (game->map.array[y / TILE][x / TILE] == '1'
			|| game->map.array[(y + PLAYER - 1) / TILE][x / TILE] == '1')
			return (true);
	}
	else if (direction == UP)
	{
		if (game->map.array[y / TILE][x / TILE] == '1'
			|| game->map.array[y / TILE][(x + PLAYER - 1) / TILE] == '1')
			return (true);
	}
	else if (direction == DOWN)
	{
		if (game->map.array[y / TILE][x / TILE] == '1'
			|| game->map.array[y / TILE][(x + PLAYER - 1) / TILE] == '1')
			return (true);
	}
	return (false);
}

void	check_collectible(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map.colls_at_start)
	{
		if (game->images.coll->instances[i].x > x - (PLAYER - OFFSET) 
			&& game->images.coll->instances[i].x < x + (PLAYER - OFFSET)
			&& game->images.coll->instances[i].y > y - (PLAYER - OFFSET)
			&& game->images.coll->instances[i].y < y + (PLAYER - OFFSET)
			&& game->images.coll->instances[i].enabled)
		{
			game->images.coll->instances[i].enabled = false;
			game->colls -= 1;
			break ;
		}
		i++;
	}
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map.array[y / TILE][x / TILE] == 'E' && game->colls == 0)
	{
		printf("You won!\n");
		mlx_terminate(game->mlx);
		free_memory(game);
		exit(0);
	}
}