/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:51:22 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/12 20:27:05 by lkonttin         ###   ########.fr       */
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

typedef struct s_map
{
	char		**array;
	int			width;
	int			height;
	int			fd;
	int			collectibles;
	int			player;
	int			exit;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

void	get_map(t_game *game, char *file);
void	validate_map(t_game *game);
void	free_memory(t_game *game);
void	error_n_exit(t_game *game, char *error_msg);
void	perror_n_exit(t_game *game, char *error_msg);
void	mlx_error(t_game *game, char *error_msg);

#endif