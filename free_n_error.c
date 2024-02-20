/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:27 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 16:51:25 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.arr != NULL)
	{
		while (game->map.arr[i] != NULL)
		{
			free(game->map.arr[i]);
			i++;
		}
		free(game->map.arr);
	}
}

void	error_n_exit(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (game->map.fd != -1)
		close(game->map.fd);
	free_memory(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(1);
}

void	mlx42_error(t_game *game, const char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)error_msg, 2);
	ft_putstr_fd("\n", 2);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_memory(game);
	exit(1);
}
