/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:57:47 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 17:24:40 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_allowed_char(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = game->map.text;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_one_pe(t_game *game)
{
	if (game->map.e_count > 1 || game->map.p_count > 1)
		return (0);
	return (1);
}

int	is_at_least_one_cpex(t_game *game)
{
	t_iterator	i;
	char		**map;

	i.y = 0;
	map = game->map.text;
	while (map[i.y])
	{
		i.x = 0;
		while (map[i.y][i.x])
		{
			if (map[i.y][i.x] == 'C')
				game->map.c_count++;
			if (map[i.y][i.x] == 'P')
				game->map.p_count++;
			if (map[i.y][i.x] == 'E')
				game->map.e_count++;
			if (map[i.y][i.x++] == 'X')
				game->map.x_count++;
		}
		i.y++;
	}
	if (game->map.c_count == 0 || game->map.p_count == 0
		|| game->map.e_count == 0 || game->map.x_count == 0)
		return (0);
	return (1);
}

int	is_rectangular(t_game *game)
{
	char	**map;

	map = game->map.text;
	while (*map)
	{
		if ((int)strlen(*map) != game->map.width)
			return (0);
		map++;
	}
	return (1);
}

int	map_parse(t_game *game, char *argv1)
{
	init_map(game, argv1);
	if (game->map.text == NULL)
	{
		ft_free_matrix(game->map.text);
		return (0);
	}
	get_map_height(game);
	get_map_width(game);
	if (is_allowed_char(game)
		&& is_at_least_one_cpex(game)
		&& is_one_pe(game)
		&& is_rectangular(game)
		&& is_surrounded_by_1(game)
		&& is_valid_path(game->map.text, game->map.width, game->map.height))
	{
		game->map.width *= TILE_SIZE_X;
		game->map.height *= TILE_SIZE_Y;
		return (1);
	}
	ft_free_matrix(game->map.text);
	return (0);
}
