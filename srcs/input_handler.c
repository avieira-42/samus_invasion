/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/23 03:47:48 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_pressed(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		free_displays(game);
	if (keysym == XK_a)
	{
		game->player.orientation = -1;
		game->player.direction.x += -1;
	}

	if (keysym == XK_d)
	{
		game->player.orientation = 1;
		game->player.direction.x += 1;
	}
	if ((keysym == XK_space || keysym == XK_w)
		&& game->player.jump.active == false
		&& is_touching_floor(game))
	{
		game->player.jump.active = true;
	}
	if (keysym == XK_s && !is_touching_floor(game))
	{
		JUMP_VEL = 0;;
	}
	return (1);
}

int	key_released(int keysym, t_game *game)
{	
	if (keysym == XK_a)
	{
		game->player.direction.x += 1;
	}
	if (keysym == XK_d)
	{
		game->player.direction.x += -1;
	}
	if (keysym == XK_s)
	{
		GRAVITY = GRAVITY_ACC;
	}
	return (1);
}


