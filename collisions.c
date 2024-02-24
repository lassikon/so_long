/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:12:16 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/24 11:03:57 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	wall_collision(t_game *game, int x, int y, int direction)
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

bool	monster_wall_collision(t_game *game, int direction)
{
	if (direction == LEFT)
	{
		if (wall_collision(game, game->mons_x - MOVE, game->mons_y, LEFT))
			return (true);
	}
	else if (direction == RIGHT)
	{
		if (wall_collision(game, game->mons_x + MONSTER, game->mons_y, RIGHT))
			return (true);
	}
	else if (direction == UP)
	{
		if (wall_collision(game, game->mons_x, game->mons_y - MOVE, UP))
			return (true);
	}
	else if (direction == DOWN)
	{
		if (wall_collision(game, game->mons_x, game->mons_y + MONSTER, DOWN))
			return (true);
	}
	return (false);
}

void	monster_player_collision(t_game *game)
{
	if (game->img.mons[0]->instances[0].x > game->player_x - (PLAYER - D)
		&& game->img.mons[0]->instances[0].x < game->player_x + (PLAYER - D)
		&& game->img.mons[0]->instances[0].y > game->player_y - (PLAYER - D)
		&& game->img.mons[0]->instances[0].y < game->player_y + (PLAYER - D))
	{
		game->over = true;
	}
}

void	collectible_collision(t_game *game, int x, int y)
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

void	exit_collision(t_game *game, int x, int y)
{
	if (game->map.arr[y / TILE][x / TILE] == 'E' && game->colls == 0)
	{
		ft_putstr_fd("You won!\n", 1);
		mlx_terminate(game->mlx);
		free_array(game);
		exit(0);
	}
}
