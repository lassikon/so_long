/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/19 18:01:43 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// malloc, free
# include "stdlib.h"

// read, write
# include "unistd.h"

// open, close
# include "fcntl.h"

// perror
# include "stdio.h"

// libraries
# include "libft/include/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define WALL_IMG "textures/48_black_wall.png"
# define FLOOR_IMG "textures/48_floor.png"
# define COLL_IMG "textures/48_sheep.png"
# define EXIT_IMG "textures/48_closed_exit.png"

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

# define MOVE 4
# define TILE 48
# define PLAYER 32
# define OFFSET 8

# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3

typedef struct s_map
{
	char		**array;
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
	mlx_texture_t		*wall_tex;
	mlx_texture_t		*floor_tex;
	mlx_texture_t		*playup_tex[3];
	mlx_texture_t		*playdown_tex[3];
	mlx_texture_t		*playleft_tex[3];
	mlx_texture_t		*playright_tex[3];
	mlx_texture_t		*coll_tex;
	mlx_texture_t		*exit_tex;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player_up[3];
	mlx_image_t		*player_down[3];
	mlx_image_t		*player_left[3];
	mlx_image_t		*player_right[3];
	mlx_image_t		*exit;
	mlx_image_t		*coll;
}	t_images;

typedef struct s_game
{
	t_map			map;
	mlx_t			*mlx;
	t_textures		textures;
	t_images		images;
	int				win_height;
	int				win_width;
	int				player_x;
	int				player_y;
	int				colls;
	int				steps;
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
void	free_memory(t_game *game);
void	error_n_exit(t_game *game, char *error_msg);
void	perror_n_exit(t_game *game, char *error_msg);
void	mlx42_error(t_game *game, const char *error_msg);

#endif