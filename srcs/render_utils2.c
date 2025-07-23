/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 03:22:14 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/23 03:39:39 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    draw_mirroredtexture(t_image *image, t_image *texture, t_point pos, long double scale)
{
	int x;
	int y;
	int color;

	x = 0;
	while (x < texture->x * scale)
	{
		y = 0;
		while (y < texture->y * scale)
		{
			color = ft_get_color(texture, (texture->x - 1 - (x / scale)), y / scale);
			if (color != 16711901 && color != 16650716)
			{
				ft_pixelput(image, pos.x + x, pos.y + y, color);
			}
			y++;
		}
		x++;
	}
}
