/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/22 12:24:53 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disable_player_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->img.pl_d[i]->instances[0].enabled = false;
		game->img.pl_u[i]->instances[0].enabled = false;
		game->img.pl_l[i]->instances[0].enabled = false;
		game->img.pl_r[i]->instances[0].enabled = false;
		i++;
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	animate_player(game, LEFT);
	if (wall_collision(game, game->player_x - MOVE, game->player_y, LEFT))
		return ;
	game->player_x -= MOVE;
	move_player_images(game, LEFT);
	game->steps += 1;
	collectible_collision(game, game->player_x, game->player_y);
	x = game->player_x / TILE;
	y = game->player_y / TILE;
	if (game->map.arr[y][x] == 'E' && game->colls == 0)
	{
		game->exit_reached = true;
		game->over = true;
	}
	print_moves(game);
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	animate_player(game, RIGHT);
	if (wall_collision(game, game->player_x + PLAYER, game->player_y, RIGHT))
		return ;
	game->player_x += MOVE;
	move_player_images(game, RIGHT);
	game->steps += 1;
	collectible_collision(game, game->player_x, game->player_y);
	x = game->player_x / TILE;
	y = game->player_y / TILE;
	if (game->map.arr[y][x] == 'E' && game->colls == 0)
	{
		game->exit_reached = true;
		game->over = true;
	}
	print_moves(game);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	animate_player(game, UP);
	if (wall_collision(game, game->player_x, game->player_y - MOVE, UP))
		return ;
	game->player_y -= MOVE;
	move_player_images(game, UP);
	game->steps += 1;
	collectible_collision(game, game->player_x, game->player_y);
	x = game->player_x / TILE;
	y = game->player_y / TILE;
	if (game->map.arr[y][x] == 'E' && game->colls == 0)
	{
		game->exit_reached = true;
		game->over = true;
	}
	print_moves(game);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	animate_player(game, DOWN);
	if (wall_collision(game, game->player_x, game->player_y + PLAYER, DOWN))
		return ;
	game->player_y += MOVE;
	move_player_images(game, DOWN);
	game->steps += 1;
	collectible_collision(game, game->player_x, game->player_y);
	x = game->player_x / TILE;
	y = game->player_y / TILE;
	if (game->map.arr[y][x] == 'E' && game->colls == 0)
	{
		game->exit_reached = true;
		game->over = true;
	}
	print_moves(game);
}
