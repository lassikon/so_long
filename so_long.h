/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/21 17:24:00 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// malloc, free, rand
# include "stdlib.h"

// read, write
# include "unistd.h"

// open, close
# include "fcntl.h"

// libraries
# include "libft/include/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define WALL_IMG "textures/48_black_wall.png"
# define FLOOR_IMG "textures/48_purple_floor.png"
# define COLL_IMG "textures/32_chest.png"
# define EXIT_IMG "textures/48_closed_exit.png"
# define OPEN_EXIT_IMG "textures/48_open_exit.png"

# define PLAYER_DOWN1 "textures/player/down1.png"
# define PLAYER_DOWN2 "textures/player/down2.png"
# define PLAYER_DOWN3 "textures/player/down3.png"
# define PLAYER_UP1 "textures/player/up1.png"
# define PLAYER_UP2 "textures/player/up2.png"
# define PLAYER_UP3 "textures/player/up3.png"
# define PLAYER_LEFT1 "textures/player/left1.png"
# define PLAYER_LEFT2 "textures/player/left2.png"
# define PLAYER_LEFT3 "textures/player/left3.png"
# define PLAYER_RIGHT1 "textures/player/right1.png"
# define PLAYER_RIGHT2 "textures/player/right2.png"
# define PLAYER_RIGHT3 "textures/player/right3.png"
# define PLAYER_FRAMES 3
# define PLAYER_ANIMATION_SPEED 8

# define MONSTER1 "textures/monster/1.png"
# define MONSTER2 "textures/monster/2.png"
# define MONSTER3 "textures/monster/3.png"
# define MONSTER4 "textures/monster/4.png"
# define MONSTER5 "textures/monster/5.png"
# define MONSTER6 "textures/monster/6.png"
# define MONSTER7 "textures/monster/7.png"
# define MONSTER8 "textures/monster/8.png"
# define MONSTER_FRAMES 8
# define MONSTER_ANIMATION_SPEED 6

# define MOVE 4
# define TILE 48
# define PLAYER 32
# define MONSTER 32
# define D 8

# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

typedef struct s_map
{
	char		**arr;
	char		**array_copy;
	int			width;
	int			height;
	int			fd;
	int			colls_at_start;
	int			player;
	int			exit;
}	t_map;

typedef struct s_textures
{
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*up[3];
	mlx_texture_t		*down[3];
	mlx_texture_t		*left[3];
	mlx_texture_t		*righ[3];
	mlx_texture_t		*mons[8];
	mlx_texture_t		*coll;
	mlx_texture_t		*exit;
	mlx_texture_t		*open_exit;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*pl_u[3];
	mlx_image_t		*pl_d[3];
	mlx_image_t		*pl_l[3];
	mlx_image_t		*pl_r[3];
	mlx_image_t		*mons[8];
	mlx_image_t		*exit;
	mlx_image_t		*open_exit;
	mlx_image_t		*coll;
	mlx_image_t		*moves;
}	t_images;

typedef struct s_game
{
	t_map			map;
	mlx_t			*mlx;
	t_textures		tex;
	t_images		img;
	int				win_height;
	int				win_width;
	int				player_x;
	int				player_y;
	int				mons_x;
	int				mons_y;
	bool			monster;
	bool			eaten_by_monster;
	bool			exit_reached;
	bool			over;
	int				colls;
	int				steps;
	int				prev_direction;
}	t_game;

void	get_map(t_game *game, char *file);
void	validate_map(t_game *game);
void	open_window(t_game *game);
void	load_textures(t_game *game);
void	textures_to_images(t_game *game);
void	keyhook(void *param);
void	animate_player(t_game *game, int direction);
void	disable_player_frames(t_game *game);
void	move_player_images(t_game *game, int direction);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
bool	check_collision(t_game *game, int x, int y, int direction);
void	check_collectible(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);
void	check_path(t_game *game);
void	print_moves(t_game *game);
void	free_memory(t_game *game);
void	error_n_exit(t_game *game, char *error_msg);
void	mlx42_error(t_game *game, const char *error_msg);
void	add_monster(t_game *game, int x, int y);
void	animate_monster(t_game *game);
void	move_monster(t_game *game);
void	check_monster_player_collision(t_game *game);

#endif