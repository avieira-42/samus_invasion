/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:00:38 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/06 19:27:45 by avieira-         ###   ########.fr       */
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
