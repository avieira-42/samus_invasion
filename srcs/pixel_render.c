/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:45:07 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 17:55:24 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	pixel_render(t_image *sprite, int x, int y, int color)
{
	char	*dest;

	if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT)
		return;
	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
