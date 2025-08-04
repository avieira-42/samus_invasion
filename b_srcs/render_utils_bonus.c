/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:48:17 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 01:58:10 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	drawobj(t_image *image, t_point pos, t_point size, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

int	ft_get_color(t_image *data, int x, int y)
{
	int	*color;

	if (x < 0 || x > data->x || y < 0 || y > data->y)
		return (0);
	color = (int *)(data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8)));
	return (*color);
}

void	drawtexture(t_image *image, t_image *texture, t_point pos,
		long double scale)
{
	int	x;
	int	y;
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

void	update_stationary_pos(t_game *game, int x, int y)
{
	game->tile.pos.x = x * TILE_SIZE_X;
	game->tile.pos.y = y * TILE_SIZE_Y;
	game->towel.pos.x = x * TILE_SIZE_X;
	game->towel.pos.y = y * TILE_SIZE_Y;
	game->portal.tmp_pos.x = x * TILE_SIZE_X;
	game->portal.tmp_pos.y = y * TILE_SIZE_Y;
	game->samus.tmp_pos.x = x * TILE_SIZE_X;
	game->samus.tmp_pos.y = y * TILE_SIZE_Y;
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map.text[y])
	{
		x = 0;
		while (game->map.text[y][x])
		{
			if (game->game_start == FALSE)
			{
				update_stationary_pos(game, x, y);
				position_sprites(game, x, y);
			}
			x++;
		}
		y++;
	}
}
