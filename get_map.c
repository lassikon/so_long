/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonttin <lkonttin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:44:49 by lkonttin          #+#    #+#             */
/*   Updated: 2024/02/20 15:40:55 by lkonttin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*sl_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	free(s1);
	free(s2);
	return (new_str);
}

static char	*get_map_str(t_game *game, char *file)
{
	char	*map_str;
	char	*line;

	game->map.fd = open(file, O_RDONLY);
	if (game->map.fd < 0)
		error_n_exit(game, "Could not open map file");
	map_str = get_next_line(game->map.fd);
	if (map_str == NULL)
		error_n_exit(game, "Could not read map");
	while (42)
	{
		line = get_next_line(game->map.fd);
		if (line == NULL)
			break ;
		map_str = sl_strjoin(map_str, line);
		if (map_str == NULL)
			error_n_exit(game, "Could not join map lines");
	}
	close(game->map.fd);
	game->map.fd = -1;
	return (map_str);
}

static void	get_map_size(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.arr[y] != NULL)
	{
		x = 0;
		while (game->map.arr[y][x] != '\0')
			x++;
		if (game->map.width == 0)
			game->map.width = x;
		else if (game->map.width != x)
			error_n_exit(game, "Map width is not consistent");
		y++;
	}
	game->map.height = y;
	game->win_width = game->map.width * TILE;
	game->win_height = game->map.height * TILE;
}

void	get_map(t_game *game, char *file)
{
	char	*map_str;

	map_str = get_map_str(game, file);
	game->map.arr = ft_split(map_str, '\n');
	if (game->map.arr == NULL)
		error_n_exit(game, "Could not split map");
	game->map.array_copy = ft_split(map_str, '\n');
	if (game->map.array_copy == NULL)
		error_n_exit(game, "Could not split map");
	free(map_str);
	get_map_size(game);
	validate_map(game);
}
