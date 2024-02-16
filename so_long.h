/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/16 15:33:36 by lkonttin         ###   ########.fr       */
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

# define WALL "textures/lava.png"
# define FLOOR "textures/lava_floor.png"
# define PLAYER "textures/chess.png"
# define COLLECTIBLE "textures/burger.png"
# define EXIT "textures/wall2.png"

# define MOVE 8
# define TILE 32
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
	mlx_texture_t		*player_tex;
	mlx_texture_t		*coll_tex;
	mlx_texture_t		*exit_tex;
}	t_textures;

typedef struct s_images
{
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player;
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
void	keyhook(void *param);
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