/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:49:26 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/08/08 03:23:51 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"       

char	**read_map(char *file_name)
{
	int		fd;
	char	**map;
	char	*line;
	char	*map_buffer;
	char	*map_holder;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_message("file doesn't exist\n", 0), NULL);
	map_holder = ft_strdup("");
	if (map_holder == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_buffer = map_holder;
		map_holder = ft_strjoin(map_buffer, line);
		(free(line), free(map_buffer));
		if (map_holder == NULL)
			return (NULL);
	}
	map = ft_split(map_holder, '\n');
	return (free(map_holder), close(fd), map);
}

void	get_map_height(t_game *game)
{
	char	**map;

	map = game->map.text;
	while (*map++)
		game->map.height++;
}

void	get_map_width(t_game *game)
{
	char	**map;

	map = game->map.text;
	game->map.width = strlen(*map);
}

int	is_only_1(char *map_line)
{
	while (*map_line)
		if (*map_line++ != '1')
			return (0);
	return (1);
}

int	is_surrounded_by_1(t_game *game)
{
	int		i;
	char	**map;

	map = game->map.text;
	i = 0;
	while (map[i])
	{
		if (i == game->map.height || i == 0)
		{
			if (!is_only_1(map[i]))
				return (error_message("map must be surrounded by walls\n", 0));
		}
		else if (map[i][0] != '1' || map[i][game->map.width - 1] != '1')
			return (error_message("map must be surrounded by walls\n", 0));
		i++;
	}
	return (1);
}
