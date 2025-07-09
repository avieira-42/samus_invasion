/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/09 02:14:27 by a-soeiro         ###   ########.fr       */
/*                                                                            */
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
			cub->ship.pos.x = x * 50 - cub->camera.x;
			cub->ship.pos.y = y * 37;
			cub->enemy.pos.x = x * 32 - cub->camera.x;
			cub->enemy.pos.y = y * 41.8;
			cub->towel.pos.x = x * 55 - cub->camera.x;
			cub->towel.pos.y = y * 43;
			cub->stairs.pos.x = x * TILE_SIZE_X - cub->camera.x;
			cub->stairs.pos.y = y * TILE_SIZE_Y;
			/*cub->portal.pos.x = x * PORTAL_SIZE_X - cub->camera.x;
			  cub->portal.pos.y = y * PORTAL_SIZE_Y*/  // IF PLAYER MEETS EXIT AND COLLECTIBLE ARE ALL GATHERED, EXIT

			// position_player(cub);
			if (cub->game_start == false && cub->map[y][x] == 'P')
			{
				PLAYER_POS_X = x * 50;
				PLAYER_POS_Y = y * 50;
			}

			// draw_element(cub, x, y)
			if (cub->map[y][x] == '1')
				drawtexture(&cub->image, &cub->tile.sprite, cub->tile.pos, 1.5);
			else if (cub->map[y][x] == 'S')
				drawtexture(&cub->image, &cub->ship.sprite, cub->ship.pos, 1.8);
			else if (cub->map[y][x] == 'C')
				drawtexture(&cub->image, &cub->towel.sprite, cub->towel.pos, 1.2);
			else if (cub->map[y][x] == 'X')
				drawtexture(&cub->image, &cub->enemy.sprite, cub->enemy.pos, 1.7);
			else if (cub->map[y][x] == 'U')
				drawtexture(&cub->image, &cub->stairs.sprite, cub->stairs.pos, 1.5);
			x++;
		}
		y++;
	}
}
