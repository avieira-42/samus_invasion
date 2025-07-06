/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/07 00:12:59 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	drawobj(t_image *image, t_point pos, t_point size, int color)
{
	int	x = 0;
	int y = 0;

	while (x < size.x)
	{
		y = 0;
		while (y < size.y)
		{
			ft_pixelput(image, pos.x + x, pos.y + y++, color);
		}
		x++;
	}
}

int ft_get_color(t_image *data, int x, int y)
{
	int    *color;

	if (x < 0 || x > data->x || y < 0 || y > data->y)
		return (0);
	color = (int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)));
	return (*color);
}

void	drawtexture(t_image *image, t_image *texture, t_point pos)
{
	int	x = 0;
	int y = 0;
	int	color;

	color = 0;
	while (x < texture->x)
	{
		y = 0;
		while (y < texture->y)
		{
			color = ft_get_color(texture, x, y);
			if (color != 16711901)
				ft_pixelput(image, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}

char	**read_map(void)
{
	int		fd;
	char	**map;
	char	*line;
	char	*map_buffer;
	char	*map_holder;

	fd = open("sprites/map.ber", O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_holder = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_buffer = map_holder;
		map_holder = ft_strjoin(map_buffer, line);
		free(line);
		free(map_buffer);
	}
	map = ft_splut(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (map);
}

void	drawtexture(t_image *image, t_image *texture, t_point pos)
void draw_map(t_cub *cub)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (cub->tile[y][x])
		{
			if (game->map[y][x] == '1')
				img_draw(cub, game->img_colect, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
