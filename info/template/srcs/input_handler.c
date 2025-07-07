/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/07 04:43:36 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_pressed(int keysym, t_cub *cub)
{
	if (keysym == XK_Escape)
		free_displays(cub);
	if (keysym == XK_a)
	{
		cub->player.direction.x += -1;
	}

	if (keysym == XK_d)
	{
		cub->player.direction.x += 1;
	}
	if (keysym == XK_space
		&& cub->player.jump.active == false
		&& cub->player.pos.y >= SCREEN_SIZE_Y - TILE_SIZE_Y * 4.7)
	{
		cub->player.jump.active = true;
	}
	return (1);
}

int	key_released(int keysym, t_cub *cub)
{	
	if (keysym == XK_a)
	{
		cub->player.direction.x += 1;
	}
	if (keysym == XK_d)
	{
		cub->player.direction.x += -1;
	}

	return (1);
}


