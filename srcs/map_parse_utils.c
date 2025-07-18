/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:50:30 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/18 19:13:58 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"       

int	get_map_height(char **map)
{
	int	map_height;

	map_height = 0;
	while (*map++)
		map_height++;
	return (map_height);
}

int	is_only_1(char *map_line)
{
	while (*map_line)
		if (*map_line++ != '1')
			return (0);
	return (1);
}

int	is_surrounded_by_1(char **map)
{
	int	i;
	int map_width;
	int	map_height;

	i = 0;
	map_width = strlen(*map);
	map_height = get_map_height(map);
	while (*map)
	{
		if (*map[0] != '1' || *map[map_width - 1] != '1')
			return (0);
		if (i == 0 || i == map_height)
			if (!is_only_1(*map))
				return (0);
		i++;
		map++;
	}
	return (1);
}
