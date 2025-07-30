/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:50:14 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/28 17:39:16 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
int	update(t_game *game)
{
	calculate_delta(game);
	game->player.touching_ground = player_touching_floor(game);
	game->player.touching_leftwall = player_touching_wall_left(game);
	game->player.touching_rightwall = player_touching_wall_right(game);
	game->player.touching_ceiling = player_touching_ceiling(game);
	game->player.touching_exit = player_touching_exit(game);
	printf("GAME_LOOP\n");
	//printf("direction: %f \n", game->player.direction.x);
	//printf("velocity.x: %f \n", game->player.velocity.x);
	//printf("delta: %f \n", game->delta); printf("pos.y: %f \n", game->player.pos.y);
	printf("player pos.x: %f \n", game->player.pos.x);
	printf("player pos.y: %f \n", game->player.pos.y);
	//printf("jump_started: %f \n", game->player.jump.t_started);
	//printf("jump_elapsed: %f \n", game->player.jump.t_elapsed);
	//printf("camera.x: %f \n", game->camera.x);
	//printf("velocity.y: %f \n", game->player.velocity.y);
	//printf("item_no: %i \n", items_count(game->items));
	//printf("tile_pos.x: %f \n", game->towel.pos.x);
	//printf("tile_pos.y: %f \n", game->towel.pos.y);
	//printf("exit_pos.x: %f \n", game->portal.pos.x);
	//printf("exit_pos.y: %f \n", game->portal.pos.y);
	//printf("enemy.x: %f \n", game->enemy.pos.x);
	//printf("enemy.y: %f \n", game->enemy.pos.y);
	//if (game->player.touching_ground)
	//printf("floor true\n");
	//if (game->items)
	//{
		//printf("item.x: %f \n", game->items->pos.x);
		//printf("item.y: %f \n", game->items->pos.y);
	//}
	//printf("vel.y: %f\n", game->player.velocity.y);
	//printf("jump_vel: %f\n", game->player.jump.velocity);
	//printf("enemy right wall:%i\n", enemy->touching_wallright);
	//printf("enemy left wall:%i\n", enemy->touching_wallleft);
	//printf("enemy_pos.x: %f\n", game->enemies->pos.x);
	//printf("enemy_pos.y: %f\n", game->enemies->pos.y);

	//INIT VELOCITY_X
	game->player.velocity.x = VELOCITY_X;


	// SCREEN LIMITS is_play_area()
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

	// JUMPING (check_jump())
	if (game->player.jump.active == true)
	{

		if (game->player.touching_ground
				&& game->player.jump.t_started > 0)
		{
			game->player.jump.active = false;
			game->player.jump.t_elapsed = 0;
			game->player.jump.t_started = 0;
		}
		if (game->player.velocity.y == 0 && game->player.jump.t_elapsed == 0)
			game->player.jump.velocity = VELOCITY_Y;

		if(game->player.jump.active == true)
		{
			if (game->player.jump.t_started == 0)
				game->player.jump.t_started = game->delta;

			game->player.jump.t_elapsed += game->delta;
		}
	}

	// FALLING UNTIL FLOOR (check falling())
	if (!game->player.touching_ground
		&& game->player.jump.active == false)
	{
		game->player.jump.velocity = -VELOCITY_Y;
	}
	if (game->player.touching_ground
		&& game->player.jump.active == false )
	{
		game->player.jump.velocity = 0;
		game->player.pos.y = game->ground_pos;
		game->player.jump.t_elapsed = 0;
		game->player.attacking = false;
		game->player.attack_counter = 0;
	}
	if (game->player.touching_ceiling)
	{
		game->player.pos.y = game->ceiling_pos;
		game->player.jump.velocity = 0;
	}

	//INIT VELOCITY (vel_init())
	game->player.velocity.y = game->player.jump.velocity + game->gravity * game->player.jump.t_elapsed;
	if (game->player.velocity.y > 1000)
		game->player.velocity.y = 1000;
	if (game->player.velocity.y < -1000)
		game->player.velocity.y = -1000;

	// MOVEMENT (get_movement())
	if (game->player.attack_timer > 24)
		game->player.pos.y += game->player.velocity.y * game->delta;
	game->player.pos.x += game->player.direction.x * game->player.velocity.x * game->delta;

	// ITEM COLLECTING
	clear_item(game);
	clear_enemy(game);
	clear_player(game);
	if (game->player.touching_exit && game->items == NULL)
		free_displays(game);
	update_attack_timer(game);
	return (1);
}

int	renderer(t_game *game)
{
	long double	multiplier;
	
	// BLACK HOLE GETS CLOSER AND PLAYER DIES
	multiplier = 1.000;
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;

	// update_camera(game);
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.x > CAMERA_END_X)
		game->camera.x = CAMERA_END_X;
	game->player.camera.x = game->player.pos.x - game->camera.x;
	game->player.camera.y = game->player.pos.y;

	(*game).image.image = mlx_new_image((*game).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*game).image.addr = mlx_get_data_addr((*game).image.image, &(*game).image.bits_per_pixel, &(*game).image.line_length, &(*game).image.endian);

	// draw_sprites
	drawtexture(&game->image, &game->bckgrnd.sprite, game->bckgrnd.pos, game->bckgrnd.scale *= multiplier);
	draw_map(game);
	draw_items(game);
	draw_walls(game);
	draw_portal(game);
	animate(game);
	display_moves(game);

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.image, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->image.image);

	return (1);
}

void	game_start(t_game *game)
{
	if (game->game_start == false)
		game->game_start = true;
}

int	game_loop(t_game *game)
{
	renderer(game);
	update(game);
	game_start(game);
	return (1);
}
