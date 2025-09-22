/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:41:09 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/15 08:55:01 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_path(char **map, int x, int y, t_point size)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (map[y][x] == 'E')
		map[y][x] = '1';
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	set_path(map, x + 1, y, size);
	set_path(map, x - 1, y, size);
	set_path(map, x, y + 1, size);
	set_path(map, x, y - 1, size);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
			{
				i--;
				free(copy[i]);
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

t_point	set_player_pos(char **map, int width, int height)
{
	int		y;
	int		x;
	t_point	p;

	y = 0;
	p.x = 0;
	p.y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'P')
			{
				p.y = y;
				p.x = x;
				return (p);
			}
			x++;
		}
		y++;
	}
	return (p);
}

int	is_valid_path(char **map, int width, int height)
{
	int		y;
	int		x;
	char	**path_map;
	t_point	p;
	t_point	size;

	y = 0;
	size.y = height;
	size.x = width;
	p = set_player_pos(map, width, height);
	path_map = copy_map(map, height);
	set_path(path_map, p.x, p.y, size);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (path_map[y][x] == 'C' || path_map[y][x] == 'E')
				return (ft_free_matrix(path_map),
					error_message("unvalid path\n", 0));
			x++;
		}
		y++;
	}
	return (ft_free_matrix(path_map), 1);
}
