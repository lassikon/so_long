/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/15 16:44:35 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	grab_collectible(t_game *game, int y, int x)
{
	int i;

	i = 0;
	while (i < game->map.colls_at_start)
	{
		if (game->images.coll->instances[i].x == x * 32
			&& game->images.coll->instances[i].y == y * 32)
		{
			game->images.coll->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	game->colls -= 1;
	game->map.array[y][x] = '0';
}

void	move_left(t_game *game)
{
	if (game->map.array[game->player_y][game->player_x - 1] == '1')
		return ;
	else if (game->map.array[game->player_y][game->player_x - 1] == 'E')
	{
		if (game->colls == 0)
		{
			game->steps += 1;
			mlx_close_window(game->mlx);
		}
		else
			return ;
	}
	else
	{
		if (game->map.array[game->player_y][game->player_x - 1] == 'C')
			grab_collectible(game, game->player_y, game->player_x - 1);
		game->map.array[game->player_y][game->player_x - 1] = 'P';
		game->map.array[game->player_y][game->player_x] = '0';
		game->player_x -= 1;
	}
	game->steps += 1;
	game->images.player->instances[0].x -= 32;
	printf("Moves: %d\n", game->steps);
}

void	move_right(t_game *game)
{
	if (game->map.array[game->player_y][game->player_x + 1] == '1')
		return ;
	else if (game->map.array[game->player_y][game->player_x + 1] == 'E')
	{
		if (game->colls == 0)
			exit(0);
		else
			return ;
	}
	else
	{
		if (game->map.array[game->player_y][game->player_x + 1] == 'C')
			grab_collectible(game, game->player_y, game->player_x + 1);
		game->map.array[game->player_y][game->player_x + 1] = 'P';
		game->map.array[game->player_y][game->player_x] = '0';
		game->player_x += 1;
	}
	game->steps += 1;
	game->images.player->instances[0].x += 32;
	printf("Moves: %d\n", game->steps);
}

void	move_up(t_game *game)
{
	if (game->map.array[game->player_y - 1][game->player_x] == '1')
		return ;
	else if (game->map.array[game->player_y - 1][game->player_x] == 'E')
	{
		if (game->colls == 0)
			exit(0);
		else
			return ;
	}
	else
	{
		if (game->map.array[game->player_y - 1][game->player_x] == 'C')
			grab_collectible(game, game->player_y - 1, game->player_x);
		game->map.array[game->player_y - 1][game->player_x] = 'P';
		game->map.array[game->player_y][game->player_x] = '0';
		game->player_y -= 1;
	}
	game->steps += 1;
	game->images.player->instances[0].y -= 32;
	printf("Moves: %d\n", game->steps);
}

void	move_down(t_game *game)
{
	if (game->map.array[game->player_y + 1][game->player_x] == '1')
		return ;
	else if (game->map.array[game->player_y + 1][game->player_x] == 'E')
	{
		if (game->colls == 0)
		{
			game->steps += 1;
			mlx_close_window(game->mlx);
		}
		else
			return ;
	}
	else
	{
		if (game->map.array[game->player_y + 1][game->player_x] == 'C')
			grab_collectible(game, game->player_y + 1, game->player_x);
		game->map.array[game->player_y + 1][game->player_x] = 'P';
		game->map.array[game->player_y][game->player_x] = '0';
		game->player_y += 1;
	}
	game->steps += 1;
	game->images.player->instances[0].y += 32;
	printf("Moves: %d\n", game->steps);
}
