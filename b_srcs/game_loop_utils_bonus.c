/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:50:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 17:10:31 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	update_loop_variables(t_game *game)
{
	calculate_delta(game);
	game->player.touching_ground = player_touching_floor(game);
	game->player.touching_leftwall = player_touching_wall_left(game);
	game->player.touching_rightwall = player_touching_wall_right(game);
	game->player.touching_ceiling = player_touching_ceiling(game);
	game->player.touching_exit = player_touching_exit(game);
	game->player.velocity.x = VELOCITY_X;
}

void	is_play_area(t_game *game)
{
	if (game->player.touching_rightwall && game->player.direction.x == -1)
	{
		game->player.velocity.x = 0;
		game->player.pos.x = game->right_wall_pos;
	}
	if (game->player.touching_leftwall && game->player.direction.x == 1)
	{
		game->player.velocity.x = 0;
		game->player.pos.x = game->left_wall_pos;
	}
	if (game->player.touching_ceiling)
	{
		game->player.pos.y = game->ceiling_pos;
		game->player.jump.velocity = 0;
	}
}

void	is_jumping(t_game *game)
{
	if (game->player.jump.active == TRUE)
	{
		if (game->player.touching_ground
			&& game->player.jump.t_started > 0)
		{
			game->player.jump.count = 0;
			game->player.jump.active = FALSE;
			game->player.jump.t_elapsed = 0;
			game->player.jump.t_started = 0;
		}
		if (game->player.velocity.y == 0 && game->player.jump.t_elapsed == 0)
			game->player.jump.velocity = VELOCITY_Y;
		if (game->player.jump.active == TRUE)
		{
			if (game->player.jump.t_started == 0)
				game->player.jump.t_started = game->delta;
			game->player.jump.t_elapsed += game->delta;
		}
	}
}

void	is_falling(t_game *game)
{
	if (!game->player.touching_ground
		&& game->player.jump.active == FALSE)
	{
		game->player.jump.velocity = -VELOCITY_Y;
	}
	if (game->player.touching_ground
		&& game->player.jump.active == FALSE)
	{
		game->player.jump.velocity = 0;
		game->player.pos.y = game->ground_pos;
		game->player.jump.t_elapsed = 0;
		game->player.attacking = FALSE;
		game->player.attack_counter = 0;
	}
}

void	clamp_falling_velocity(t_game *game)
{
	game->player.velocity.y = game->player.jump.velocity
		+ game->gravity * game->player.jump.t_elapsed;
	if (game->player.velocity.y > 1000)
		game->player.velocity.y = 1000;
	if (game->player.velocity.y < -1000)
		game->player.velocity.y = -1000;
}
