/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:09:07 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 13:44:34 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

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
