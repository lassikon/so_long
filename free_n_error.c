/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:27 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/12 20:28:37 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.array != NULL)
	{
		while (game->map.array[i] != NULL)
		{
			free(game->map.array[i]);
			i++;
		}
		free(game->map.array);
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
	exit(1);
}

void	perror_n_exit(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	perror(error_msg);
	if (game->map.fd != -1)
		close(game->map.fd);
	free_memory(game);
	exit(1);
}

/* void	mlx_error(t_game *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	free_memory(game);
	exit(1);
} */