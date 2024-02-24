/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:27 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/24 11:03:33 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_n_exit(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (game->map.fd != -1)
		close(game->map.fd);
	free_array(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(1);
}

void	mlx42_error(t_game *game, const char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (game->map.fd != -1)
		close(game->map.fd);
	if (game->mlx)
		mlx_terminate(game->mlx);
	else
		free_textures(game);
	free_array(game);
	exit(1);
}
