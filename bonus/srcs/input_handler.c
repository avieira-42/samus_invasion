/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/30 01:13:11 by a-soeiro         ###   ########.fr       */
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
		&& game->player.jump.active == FALSE
		&& player_touching_floor(game))
		game->player.jump.active = TRUE;
	if (keysym == XK_s && game->player.attack_counter == 0
		&& !player_touching_floor(game))
	{
		game->player.jump.velocity = 0;
		game->player.attacking = TRUE;
		game->player.attack_timer = 0;
		game->player.attack_counter = 1;
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
		game->gravity = GRAVITY_ACC;
	}
	return (1);
}
