/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:01:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/21 17:01:30 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

t_point get_mouse_position(t_cub *cub)
{
	int x = 0;
	int y = 0;

	mlx_mouse_get_pos(cub->mlx_ptr, cub->win_ptr, \
			&x, &y);
	if (x > SCREEN_SIZE_X)
		x = SCREEN_SIZE_X;
	else if (x < 0)
		x = 0;
	if (y > SCREEN_SIZE_Y)
		y = SCREEN_SIZE_Y;
	else if (y < 0)
		y = 0;
	return ((t_point){x, y});
}
