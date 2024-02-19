/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:12 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 18:02:06 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disable_player_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		game->images.player_down[i]->instances[0].enabled = false;
		game->images.player_up[i]->instances[0].enabled = false;
		game->images.player_left[i]->instances[0].enabled = false;
		game->images.player_right[i]->instances[0].enabled = false;
		i++;
	}
}

void	move_left(t_game *game)
{
	animate_player(game, LEFT);
	if (check_collision(game, game->player_x - MOVE, game->player_y, LEFT))
		return ;
	game->player_x -= MOVE;
	move_player_images(game, LEFT);
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_right(t_game *game)
{
	animate_player(game, RIGHT);
	if (check_collision(game, game->player_x + PLAYER, game->player_y, RIGHT))
		return ;
	game->player_x += MOVE;
	move_player_images(game, RIGHT);
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_up(t_game *game)
{
	animate_player(game, UP);
	if (check_collision(game, game->player_x, game->player_y - MOVE, UP))
		return ;
	game->player_y -= MOVE;
	move_player_images(game, UP);
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}

void	move_down(t_game *game)
{
	animate_player(game, DOWN);
	if (check_collision(game, game->player_x, game->player_y + PLAYER, DOWN))
		return ;
	game->player_y += MOVE;
	move_player_images(game, DOWN);
	game->steps += 1;
	check_collectible(game, game->player_x, game->player_y);
	check_exit(game, game->player_x, game->player_y);
	printf("Moves: %d\n", game->steps);
}
