/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:57:47 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/18 19:09:42 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_allowed_char(char **map)
{
	while (*map)
	{
		while (**map)
		{
			if (**map != '1' && **map != '0'
				&& **map != 'E' && **map != 'P'
				&& **map != 'C' && **map != 'X')
				return (0);
			(*map)++;
		}
		map++;
	}
	return (1);
}

int	is_one_PE(char **map)
{
	t_map	grid;

	grid.P_count = 0;
	grid.E_count = 0;
	while (*map)
	{
		while (**map)
		{
			if (**map == 'P')
				grid.P_count++;
			else if (**map == 'E')
				grid.E_count++;
			if (grid.E_count > 1 || grid.P_count > 1)
				return (0);
			(*map)++;
		}
		map++;
	}
	return (1);
}

int	is_at_least_one_CPEX(char **map)
{
	t_map	grid;

	grid.C_count = 0;
	grid.P_count = 0;
	grid.E_count = 0;
	grid.X_count = 0;
	while (*map)
	{
		while (**map)
		{
			if (**map == 'C')
				grid.C_count++;
			else if (**map == 'P')
				grid.P_count++;
			else if (**map == 'E')
				grid.E_count++;
			else if (*(*map)++ == 'X')
				grid.X_count++;
		}
		map++;
	}
	if (grid.C_count == 0 || grid.P_count == 0
		|| grid.E_count == 0 || grid.X_count == 0)
			return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int	map_width;

	map_width = strlen(*map);
	while (*map)
	{
		if ((int)strlen(*map) != map_width)
			return (0);
		map++;
	}
	return (1);
}

int	map_parse(char **map)
{
	if (is_allowed_char(map)
		&& is_at_least_one_CPEX(map)
		&& is_one_PE(map)
		&& is_rectangular(map)
		&& is_surrounded_by_1(map))
		return (1);
		// Path to collectibles then exit has to be possible
	return (0);
}
