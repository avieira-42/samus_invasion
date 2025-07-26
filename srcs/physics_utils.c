/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */ /*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:38:07 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/25 13:48:07 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    update_enemy_orientation(t_game *game, t_enemy *enemy)
{
	if (ft_abs(enemiy.tmp_pos.y - enemy.pos.y) > 400
			|| enemy.touching.wall_right
			|| enemy.touching.wall_left)
	{
		enemy.tmp_pos.y = enemy.pos.y;
		enemy.orientation *= -1;
	}
}

void	move_enemies(t_game *game)
{
	{
		t_enemy *enemies;
		t_point pos;

		enemies = game->enemies;
		while (enemies)
		{
			update_enemy_orientation(game, enemies);
			update_enemy_pos(game, enemies);
			animate_enemy(game, enemis)
			enemies = enemies->next;
		}
	}
}
void	update_enemy_pos(t_game *game)
{
	//INIT VELOCITY_X
	ENEMY_VEL_X = ENEMY_VELOCITY_X;


	// SCREEN LIMITS is_play_area()
	if (ENEMY_TOUCHING_RIGHTWALL && PLAYER_DIR_X == -1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = game->right_wall_pos;
	}
	if (PLAYER_TOUCHING_LEFTWALL && PLAYER_DIR_X == 1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = game->left_wall_pos;
	}

	// JUMPING (check_jump())
	if (game->player.jump.active == true)
	{

		if (PLAYER_TOUCHING_FLOOR
				&& game->player.jump.t_started > 0)
		{
			game->player.jump.active = false;
			game->player.jump.t_elapsed = 0;
			game->player.jump.t_started = 0;
		}
		if (PLAYER_VEL_Y == 0 && game->player.jump.t_elapsed == 0)
			JUMP_VEL = VELOCITY_Y;

		if(game->player.jump.active == true)
		{
			if (game->player.jump.t_started == 0)
				game->player.jump.t_started = game->delta;

			game->player.jump.t_elapsed += game->delta;
		}
	}

	// FALLING UNTIL FLOOR (check falling())
	if (!PLAYER_TOUCHING_FLOOR
		&& game->player.jump.active == false)
	{
		JUMP_VEL = -VELOCITY_Y;
	}
	if (PLAYER_TOUCHING_FLOOR
		&& game->player.jump.active == false )
	{
		JUMP_VEL = 0;
		PLAYER_POS_Y = game->ground_pos;
		game->player.jump.t_elapsed = 0;
		ATTACKING = false;
		ATTACK_COUNTER = 0;
	}
	if (PLAYER_TOUCHING_CEILING)
	{
		PLAYER_POS_Y = game->ceiling_pos;
		JUMP_VEL = 0;
	}

	//INIT VELOCITY (vel_init())
	PLAYER_VEL_Y = JUMP_VEL + GRAVITY * game->player.jump.t_elapsed;
	if (PLAYER_VEL_Y > 1000)
		PLAYER_VEL_Y = 1000;
	if (PLAYER_VEL_Y < -1000)
		PLAYER_VEL_Y = -1000;

	// MOVEMENT (get_movement())
	if (ATTACK_TIMER > 24)
		PLAYER_POS_Y += PLAYER_VEL_Y * DELTA_T;
	PLAYER_POS_X += PLAYER_DIR_X * PLAYER_VEL_X * DELTA_T;

	// ITEM COLLECTING
	clear_item(game);
	if (PLAYER_TOUCHING_EXIT && game->items == NULL)
		free_displays(game);
	update_attack_timer(game);
	return (1);
}
