/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by avieira-          #+#    #+#             */
/*   Updated: 2025/09/15 11:21:20 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/samus_invasion.h"

void	key_pressed2(int keysym, t_game *game)
{
	if ((keysym == XK_s || keysym == XK_Down)
		&& game->player.attack_counter == 0
		&& !player_touching_floor(game))
	{
		game->player.jump.velocity = 0;
		game->player.attacking = TRUE;
		game->player.attack_timer = 0;
		game->player.attack_counter = 1;
	}
	if (keysym == XK_Return && game->end == TRUE)
	{
		game->end = FALSE;
		game->game_start = FALSE;
		free_death_screen(game);
		free_victory_screen(game);
		free_sprites(game);
		free_items(game->items);
		free_enemies(game->enemies);
		free_walls(game->walls);
		init_game(game);
	}
}

int	key_pressed(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		free_displays(game);
	if (keysym == XK_a || keysym == XK_Left)
	{
		game->player.orientation = -1;
		game->player.direction.x += -1;
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		game->player.orientation = 1;
		game->player.direction.x += 1;
	}
	if ((keysym == XK_space || keysym == XK_w)
		&& game->player.jump.count < game->player.jump.max_count
		&& !game->player.attacking)
	{
		game->player.jump.count++;
		game->player.jump.t_started = 0;
		game->player.jump.t_elapsed = 0;
		game->player.jump.active = TRUE;
		game->player.jump.velocity = VELOCITY_Y;
	}
	key_pressed2(keysym, game);
	return (1);
}

int	key_released(int keysym, t_game *game)
{
	if (keysym == XK_a || keysym == XK_Left)
	{
		game->player.direction.x += 1;
	}
	if (keysym == XK_d || keysym == XK_Right)
	{
		game->player.direction.x += -1;
	}
	if (keysym == XK_s || keysym == XK_Down)
	{
		game->gravity = GRAVITY_ACC;
	}
	return (1);
}
