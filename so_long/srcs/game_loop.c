/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/17 16:04:52 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
int	update(t_game *game)
{
	calculate_Delta(game);
	TOUCHING_FLOOR = is_touching_floor(game);
	TOUCHING_LEFTWALL = is_touching_wall_left(game);
	TOUCHING_RIGHTWALL = is_touching_wall_right(game);
	TOUCHING_CEILING = is_touching_ceiling(game);
	TOUCHING_EXIT = is_touching_exit(game);
	//printf("direction: %f \n", game->player.direction.x);
	//printf("velocity.x: %f \n", game->player.velocity.x);
	//printf("delta: %f \n", game->delta); printf("pos.y: %f \n", game->player.pos.y);
	printf("pos.x: %f \n", game->player.pos.x);
	printf("pos.y: %f \n", game->player.pos.y);
	//printf("jump_started: %f \n", game->player.jump.t_started);
	//printf("jump_elapsed: %f \n", game->player.jump.t_elapsed);
	//printf("camera.x: %f \n", game->camera.x);
	//printf("velocity.y: %f \n", game->player.velocity.y);
	//printf("item_no: %i \n", items_count(game->items));
	//printf("tile_pos.x: %f \n", game->towel.pos.x);
	//printf("tile_pos.y: %f \n", game->towel.pos.y);
	printf("exit_pos.x: %f \n", game->portal.pos.x);
	printf("exit_pos.y: %f \n", game->portal.pos.y);
	printf("enemy.x: %f \n", game->enemy.pos.x);
	printf("enemy.y: %f \n", game->enemy.pos.y);
	if (game->items)
	{
		printf("item.x: %f \n", game->items->pos.x);
		printf("item.y: %f \n", game->items->pos.y);
	}

	//INIT VELOCITY_X
	PLAYER_VEL_X = VELOCITY_X;


	// SCREEN LIMITS is_play_area()
	if (TOUCHING_RIGHTWALL && PLAYER_DIR_X == -1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = game->right_wall_pos;
	}
	if (TOUCHING_LEFTWALL && PLAYER_DIR_X == 1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = game->left_wall_pos;
	}


	// JUMPING (check_jump())
	if (game->player.jump.active == true)
	{

		if (TOUCHING_FLOOR
				&& game->player.jump.t_started > 0)
		{
			game->player.jump.active = false;
			game->player.jump.t_elapsed = 0;
			game->player.jump.t_started = 0;
		}
		if (PLAYER_VEL_Y == 0 && game->player.jump.t_started == 0)
			JUMP_VEL = VELOCITY_Y;

		if(game->player.jump.active == true)
		{
			if (game->player.jump.t_started == 0)
				game->player.jump.t_started = game->delta;

			game->player.jump.t_elapsed += game->delta;
		}
	}

	// FALLING UNTIL FLOOR (check falling())
	if (!TOUCHING_FLOOR
		&& game->player.jump.active == false)
	{
		JUMP_VEL = -VELOCITY_Y;
	}
	if (TOUCHING_FLOOR
		&& game->player.jump.active == false )
	{
		JUMP_VEL = 0;
		PLAYER_POS_Y = game->ground_pos;
		game->player.jump.t_elapsed = 0;
		if (TOUCHING_RIGHTWALL)
			PLAYER_POS_X = game->right_wall_pos;
		if (TOUCHING_LEFTWALL)
			PLAYER_POS_X = game->left_wall_pos;
	}
	if (TOUCHING_CEILING)
		JUMP_VEL = 0;

	//INIT VELOCITY (vel_init())
	PLAYER_VEL_Y = JUMP_VEL + GRAVITY * game->player.jump.t_elapsed;

	// MOVEMENT (get_movement())
	PLAYER_POS_Y += PLAYER_VEL_Y * DELTA_T;
	PLAYER_POS_X += PLAYER_DIR_X * PLAYER_VEL_X * DELTA_T;

	// ITEM COLLECTING
	clear_item(game);
	if (TOUCHING_EXIT && game->items == NULL)
		free_displays(game);
	return (1);
}

int	renderer(t_game *game)
{
	long double	multiplier;

	multiplier = 1.000;
	game->camera.x = game->player.pos.x - SCREEN_SIZE_X / 2;

	// update_camera(game);
	if (game->camera.x < 0)
		game->camera.x = 0;
	if (game->camera.x > CAMERA_END_X)
		game->camera.x = CAMERA_END_X;
	game->player.camera.x = PLAYER_POS_X - game->camera.x;
	game->player.camera.y = PLAYER_POS_Y;

	(*game).image.image = mlx_new_image((*game).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*game).image.addr = mlx_get_data_addr((*game).image.image, &(*game).image.bits_per_pixel, &(*game).image.line_length, &(*game).image.endian);

	drawtexture(&game->image, &game->bckgrnd.sprite, game->bckgrnd.pos, game->bckgrnd.scale *= multiplier);
	draw_map(game);
	draw_items(game);
	draw_walls(game);
	draw_portal(game);
	draw_enemy(game);
	drawtexture(&game->image, &game->player.sprite, game->player.camera, 1);

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
	update(game);
	renderer(game);
	game_start(game);
	return (1);
}
