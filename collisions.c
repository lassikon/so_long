/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:12:16 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 15:14:27 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_collision(t_game *game, int x, int y, int direction)
{
	if (direction == LEFT)
	{
		if (game->map.arr[y / TILE][x / TILE] == '1' ||
			game->map.arr[(y + PLAYER - 1) / TILE][x / TILE] == '1')
			return (true);
	}
	else if (direction == RIGHT)
	{
		if (game->map.arr[y / TILE][(x - D) / TILE] == '1' ||
			game->map.arr[(y + PLAYER - 1) / TILE][(x - D) / TILE] == '1')
			return (true);
	}
	else if (direction == UP)
	{
		if (game->map.arr[(y - D) / TILE][x / TILE] == '1' ||
			game->map.arr[(y - D) / TILE][(x + PLAYER - D - 1) / TILE] == '1')
			return (true);
	}
	else if (direction == DOWN)
	{
		if (game->map.arr[y / TILE][x / TILE] == '1' ||
			game->map.arr[y / TILE][(x + PLAYER - D - 1) / TILE] == '1')
			return (true);
	}
	return (false);
}

void	check_monster_player_collision(t_game *game)
{
	if (game->img.mons[0]->instances[0].x > game->player_x - (PLAYER - D)
		&& game->img.mons[0]->instances[0].x < game->player_x + (PLAYER - D)
		&& game->img.mons[0]->instances[0].y > game->player_y - (PLAYER - D)
		&& game->img.mons[0]->instances[0].y < game->player_y + (PLAYER - D))
	{
		game->eaten_by_monster = true;
		game->over = true;
	}
}

void	check_collectible(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map.colls_at_start)
	{
		if (game->img.coll->instances[i].x > x - (PLAYER - D)
			&& game->img.coll->instances[i].x < x + (PLAYER - D)
			&& game->img.coll->instances[i].y > y - (PLAYER - D)
			&& game->img.coll->instances[i].y < y + (PLAYER - D)
			&& game->img.coll->instances[i].enabled)
		{
			game->img.coll->instances[i].enabled = false;
			game->colls -= 1;
			break ;
		}
		i++;
	}
	if (game->colls == 0)
	{
		game->img.exit->instances[0].enabled = false;
		game->img.open_exit->instances[0].enabled = true;
	}
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map.arr[y / TILE][x / TILE] == 'E' && game->colls == 0)
	{
		ft_putstr_fd("You won!\n", 1);
		mlx_terminate(game->mlx);
		free_memory(game);
		exit(0);
	}
}
