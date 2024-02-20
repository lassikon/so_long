/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:48:35 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 15:54:41 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animate_left(t_game *game)
{
	static int	i = 0;
	static int	frame = 0;

	if (game->prev_direction != LEFT)
	{
		i = 0;
		frame = PLAYER_ANIMATION_SPEED;
		game->prev_direction = LEFT;
	}
	if (frame == PLAYER_ANIMATION_SPEED)
	{
		disable_player_frames(game);
		game->img.pl_l[i]->instances[0].enabled = true;
		i++;
		if (i == PLAYER_FRAMES)
			i = 0;
		frame = 0;
	}
	else
		frame++;
}

static void	animate_right(t_game *game)
{
	static int	i = 0;
	static int	frame = 0;

	if (game->prev_direction != RIGHT)
	{
		i = 0;
		frame = PLAYER_ANIMATION_SPEED;
		game->prev_direction = RIGHT;
	}
	if (frame == PLAYER_ANIMATION_SPEED)
	{
		disable_player_frames(game);
		game->img.pl_r[i]->instances[0].enabled = true;
		i++;
		if (i == PLAYER_FRAMES)
			i = 0;
		frame = 0;
	}
	else
		frame++;
}

static void	animate_up(t_game *game)
{
	static int	i = 0;
	static int	frame = 0;

	if (game->prev_direction != UP)
	{
		i = 0;
		frame = PLAYER_ANIMATION_SPEED;
		game->prev_direction = UP;
	}
	if (frame == PLAYER_ANIMATION_SPEED)
	{
		disable_player_frames(game);
		game->img.pl_u[i]->instances[0].enabled = true;
		i++;
		if (i == PLAYER_FRAMES)
			i = 0;
		frame = 0;
	}
	else
		frame++;
}

static void	animate_down(t_game *game)
{
	static int	i = 0;
	static int	frame = 0;

	if (game->prev_direction != DOWN)
	{
		i = 0;
		frame = PLAYER_ANIMATION_SPEED;
		game->prev_direction = DOWN;
	}
	if (frame == PLAYER_ANIMATION_SPEED)
	{
		disable_player_frames(game);
		game->img.pl_d[i]->instances[0].enabled = true;
		i++;
		if (i == PLAYER_FRAMES)
			i = 0;
		frame = 0;
	}
	else
		frame++;
}

void	animate_player(t_game *game, int direction)
{
	if (direction == UP)
		animate_up(game);
	else if (direction == DOWN)
		animate_down(game);
	else if (direction == LEFT)
		animate_left(game);
	else if (direction == RIGHT)
		animate_right(game);
}
