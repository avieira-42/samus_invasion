/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 17:45:41 by a-soeiro         ###   ########.fr       */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawobj(t_image *image, t_point pos, t_point size, int color)
{
	int	x = 0; int y = 0;

	while (x < size.x)
	{
		y = 0; while (y < size.y)
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

void draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			// update_stationary_pos(game, x, y)
			game->tile.pos.x = x * TILE_SIZE_X;
			game->tile.pos.y = y * TILE_SIZE_Y;
			game->towel.pos.x = x * TILE_SIZE_X;
			game->towel.pos.y = y * TILE_SIZE_Y;
			game->portal.tmp_pos.x = x * TILE_SIZE_X;
			game->portal.tmp_pos.y = y * TILE_SIZE_Y;
			game->enemy.tmp_pos.x = x * TILE_SIZE_X;
			game->enemy.tmp_pos.y = y * TILE_SIZE_Y;

			if (game->game_start == false)
			{
				if (game->map[y][x] == 'P')
				{
					// position_player(cu);
					PLAYER_POS_X = x * TILE_SIZE_X;
					PLAYER_POS_Y = y * TILE_SIZE_Y;
					PLAYER_TMP_POS_X = x * TILE_SIZE_X;
					PLAYER_TMP_POS_Y = y * TILE_SIZE_Y;
				}
				else if (game->map[y][x] == 'C') //position_items(game);
					position_item(game);
				else if (game->map[y][x] == '1')
					position_wall(game);
				// draw_element(game, x, y)
				else if (game->map[y][x] == 'X')
					position_enemy(game); 
				else if (game->map[y][x] == 'E')
					position_portal(game);
			}
			x++;
		}
		y++;
	}
}
