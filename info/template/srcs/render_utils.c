/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/07 04:36:09 by a-soeiro         ###   ########.fr       */
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

void	drawtexture(t_image *image, t_image *texture, t_point pos, float scale)
{
	int	x;
	int y;
	int	color;

	color = 0;
	x = 0;
	y = 0;
	while (x < texture->x * scale)
	{
		y = 0;
		while (y < texture->y * scale)
		{
			color = ft_get_color(texture, x / scale, y / scale);
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
	map = ft_split(map_holder, '\n');
	free(map_holder);
	close(fd);
	return (map);
}

void draw_map(t_cub *cub)
{
	int		y;
	int		x;
	t_point	pos;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
			{
				cub->camera.x = cub->player.pos.x - SCREEN_SIZE_X / 2;
				cub->camera.y = cub->player.pos.y - SCREEN_SIZE_Y / 2;
				pos.x = x * TILE_SIZE_X - cub->camera.x;
				pos.y = y * TILE_SIZE_Y - cub->camera.y;
				drawtexture(&cub->image, &cub->tile, pos, 1.5);
			}
			x++;
		}
		y++;
	}
}
