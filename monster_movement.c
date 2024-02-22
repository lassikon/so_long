/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:38:33 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/22 15:18:50 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_monster(t_game *game)
{
	static int	i = 0;
	static int	frame = 0;

	if (frame == MONSTER_ANIMATION_SPEED)
	{
		game->img.mons[i]->instances[0].enabled = false;
		i++;
		if (i == MONSTER_FRAMES)
			i = 0;
		game->img.mons[i]->instances[0].enabled = true;
		frame = 0;
	}
	else
		frame++;
}

static void	move_monster_images(t_game *game, int direction)
{
	int	i;

	i = 0;
	while (i < MONSTER_FRAMES)
	{
		if (direction == UP)
			game->img.mons[i]->instances[0].y -= MOVE;
		else if (direction == DOWN)
			game->img.mons[i]->instances[0].y += MOVE;
		else if (direction == LEFT)
			game->img.mons[i]->instances[0].x -= MOVE;
		else if (direction == RIGHT)
			game->img.mons[i]->instances[0].x += MOVE;
		else
			return ;
		i++;
	}
}

static void	update_monster_position(t_game *game, int direction)
{
	if (direction == UP)
		game->mons_y -= MOVE;
	else if (direction == DOWN)
		game->mons_y += MOVE;
	else if (direction == LEFT)
		game->mons_x -= MOVE;
	else if (direction == RIGHT)
		game->mons_x += MOVE;
	else
		return ;
}

static void	bounce_monster(t_game *game, int direction)
{
	if (direction == UP)
	{
		move_monster_images(game, DOWN);
		update_monster_position(game, DOWN);
	}
	else if (direction == DOWN)
	{
		move_monster_images(game, UP);
		update_monster_position(game, UP);
	}
	else if (direction == LEFT)
	{
		move_monster_images(game, RIGHT);
		update_monster_position(game, RIGHT);
	}
	else if (direction == RIGHT)
	{
		move_monster_images(game, LEFT);
		update_monster_position(game, LEFT);
	}
	else
		return ;
}

void	move_monster(t_game *game)
{
	static int	direction = 0;
	static int	duration = 30;

	if (duration == 0)
	{
		duration = rand() % (60 - 10 + 1) + 10;
		direction = rand() % 5;
	}
	monster_player_collision(game);
	if (monster_wall_collision(game, direction))
	{
		bounce_monster(game, direction);
		direction = rand() % 5;
		return ;
	}
	move_monster_images(game, direction);
	update_monster_position(game, direction);
	duration--;
}
