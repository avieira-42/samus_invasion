/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/16 21:11:22 by a-soeiro         ###   ########.fr       */
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
		&& is_touching_floor(cub))
	{
		cub->player.jump.active = true;
	}
	if (keysym == XK_w)
	{
		cub->player.direction.y += -1;
	}
	if (keysym == XK_s)
	{
		cub->player.direction.y += 1;
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
	if (keysym == XK_w)
	{
		cub->player.direction.y += 1;
	}
	if (keysym == XK_s)
	{
		cub->player.direction.y += -1;
	}

	return (1);
}


