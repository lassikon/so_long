/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:42:05 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 17:53:13 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player_up_images(t_game *game, int direction)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (direction == UP)
			game->images.player_up[i]->instances[0].y -= MOVE;
		else if (direction == DOWN)
			game->images.player_up[i]->instances[0].y += MOVE;
		else if (direction == LEFT)
			game->images.player_up[i]->instances[0].x -= MOVE;
		else if (direction == RIGHT)
			game->images.player_up[i]->instances[0].x += MOVE;
		i++;
	}
}

static void	move_player_down_images(t_game *game, int direction)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (direction == UP)
			game->images.player_down[i]->instances[0].y -= MOVE;
		else if (direction == DOWN)
			game->images.player_down[i]->instances[0].y += MOVE;
		else if (direction == LEFT)
			game->images.player_down[i]->instances[0].x -= MOVE;
		else if (direction == RIGHT)
			game->images.player_down[i]->instances[0].x += MOVE;
		i++;
	}
}

static void	move_player_left_images(t_game *game, int direction)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (direction == UP)
			game->images.player_left[i]->instances[0].y -= MOVE;
		else if (direction == DOWN)
			game->images.player_left[i]->instances[0].y += MOVE;
		else if (direction == LEFT)
			game->images.player_left[i]->instances[0].x -= MOVE;
		else if (direction == RIGHT)
			game->images.player_left[i]->instances[0].x += MOVE;
		i++;
	}
}

static void	move_player_right_images(t_game *game, int direction)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (direction == UP)
			game->images.player_right[i]->instances[0].y -= MOVE;
		else if (direction == DOWN)
			game->images.player_right[i]->instances[0].y += MOVE;
		else if (direction == LEFT)
			game->images.player_right[i]->instances[0].x -= MOVE;
		else if (direction == RIGHT)
			game->images.player_right[i]->instances[0].x += MOVE;
		i++;
	}
}

void	move_player_images(t_game *game, int direction)
{
	move_player_up_images(game, direction);
	move_player_down_images(game, direction);
	move_player_left_images(game, direction);
	move_player_right_images(game, direction);
}
