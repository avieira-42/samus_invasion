/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 03:40:52 by a-soeiro         ###   ########.fr       */
/* ************************************************************************** */

#include "../includes/cub.h"

void	drawobj(t_image *image, t_point pos, t_point size, int color)
{
	int	x = 0; int y = 0;

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

void	drawtexture(t_image *image, t_image *texture, t_point pos, long double scale)
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
			if (color != 16711901 && color != 16650716)
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

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			// update_stationary_pos(cub, x, y)
			cub->tile.pos.x = x * TILE_SIZE_X - cub->camera.x;
			cub->tile.pos.y = y * TILE_SIZE_Y;
			cub->enemy.pos.x = x * TILE_SIZE_X - cub->camera.x;
			cub->enemy.pos.y = y * TILE_SIZE_Y;
			cub->towel.pos.x = x * TILE_SIZE_X;
			cub->towel.pos.y = y * TILE_SIZE_Y;
			cub->portal.tmp_pos.x = x * TILE_SIZE_X - cub->camera.x;
			cub->portal.tmp_pos.y = y * TILE_SIZE_Y;

			if (cub->game_start == false)
			{
				if (cub->map[y][x] == 'P')
				{
					// position_player(cu);
					PLAYER_POS_X = x * TILE_SIZE_X;
					PLAYER_POS_Y = y * TILE_SIZE_Y;
				}
				else if (cub->map[y][x] == 'C') //position_items(cub);
					position_item(cub);
				else if (cub->map[y][x] == '1')
					position_wall(cub);
				else if (cub->map[y][x] == 'E')
					position_portal(cub);
			}

			// draw_element(cub, x, y)
			if (cub->map[y][x] == 'X')
				drawtexture(&cub->image, &cub->enemy.sprite, cub->enemy.pos, 1);
			x++;
		}
		y++;
	}
}
