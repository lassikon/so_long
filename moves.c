/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/16 15:13:28 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	if (check_collision(game, game->player_x - MOVE, game->player_y, LEFT))
		return ;
	game->player_x -= MOVE;
	game->images.player->instances[0].x = game->player_x;
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_right(t_game *game)
{
	if (check_collision(game, game->player_x + TILE, game->player_y, RIGHT))
		return ;
	game->player_x += MOVE;
	game->images.player->instances[0].x = game->player_x;
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_up(t_game *game)
{
	if (check_collision(game, game->player_x, game->player_y - MOVE, UP))
		return ;
	game->player_y -= MOVE;
	game->images.player->instances[0].y = game->player_y;
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_down(t_game *game)
{
	if (check_collision(game, game->player_x, game->player_y + TILE, DOWN))
		return ;
	game->player_y += MOVE;
	game->images.player->instances[0].y = game->player_y;
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

