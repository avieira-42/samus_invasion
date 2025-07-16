/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/16 23:50:44 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>
int	update(t_cub *cub)
{
	calculate_Delta(cub);
	TOUCHING_FLOOR = is_touching_floor(cub);
	TOUCHING_LEFTWALL = is_touching_wall_left(cub);
	TOUCHING_RIGHTWALL = is_touching_wall_right(cub);
	TOUCHING_CEILING = is_touching_ceiling(cub);
	//printf("direction: %f \n", cub->player.direction.x);
	//printf("velocity.x: %f \n", cub->player.velocity.x);
	//printf("delta: %f \n", cub->delta); printf("pos.y: %f \n", cub->player.pos.y);
	printf("pos.x: %f \n", cub->player.pos.x);
	printf("pos.y: %f \n", cub->player.pos.y);
	//printf("jump_started: %f \n", cub->player.jump.t_started);
	//printf("jump_elapsed: %f \n", cub->player.jump.t_elapsed);
	//printf("camera.x: %f \n", cub->camera.x);
	//printf("velocity.y: %f \n", cub->player.velocity.y);
	//printf("item_no: %i \n", items_count(cub->items));
	printf("tile_pos.x: %f \n", cub->towel.pos.x);
	printf("tile_pos.y: %f \n", cub->towel.pos.y);
	if (cub->items)
	{
		printf("item.x: %f \n", cub->items->pos.x);
		printf("item.y: %f \n", cub->items->pos.y);
	}

	//INIT VELOCITY_X
	PLAYER_VEL_X = VELOCITY_X;


	// SCREEN LIMITS is_play_area()
	if (TOUCHING_RIGHTWALL && PLAYER_DIR_X == -1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = cub->right_wall_pos;
	}
	if (TOUCHING_LEFTWALL && PLAYER_DIR_X == 1)
	{
		PLAYER_VEL_X = 0;
		PLAYER_POS_X = cub->left_wall_pos;
	}


	// JUMPING (check_jump())
	if (cub->player.jump.active == true)
	{

		if (TOUCHING_FLOOR
				&& cub->player.jump.t_started > 0)
		{
			cub->player.jump.active = false; cub->player.jump.t_elapsed = 0; cub->player.jump.t_started = 0;
			cub->player.jump.d_traveled = 0;
		}
		if (PLAYER_VEL_Y == 0 && cub->player.jump.t_started == 0)
			JUMP_VEL = VELOCITY_Y;

		if(cub->player.jump.active == true)
		{
			if (cub->player.jump.t_started == 0)
				cub->player.jump.t_started = cub->delta;

			cub->player.jump.t_elapsed += cub->delta;
		}
	}

	// FALLING UNTIL FLOOR (check falling())
	if (!TOUCHING_FLOOR
		&& cub->player.jump.active == false)
	{
		JUMP_VEL = -VELOCITY_Y;
	}
	if (TOUCHING_FLOOR
		&& cub->player.jump.active == false )
	{
		JUMP_VEL = 0;
		PLAYER_POS_Y = cub->ground_pos;
		if (TOUCHING_RIGHTWALL)
			PLAYER_POS_X = cub->right_wall_pos;
		if (TOUCHING_LEFTWALL)
			PLAYER_POS_X = cub->left_wall_pos;
	}
	if (TOUCHING_CEILING)
		JUMP_VEL = 0;

	//INIT VELOCITY (vel_init())
	PLAYER_VEL_Y = JUMP_VEL + GRAVITY * cub->player.jump.t_elapsed;

	// MOVEMENT (get_movement())
	PLAYER_POS_Y += PLAYER_VEL_Y * DELTA_T;
	PLAYER_POS_X += PLAYER_DIR_X * PLAYER_VEL_X * DELTA_T;

	// ITEM COLLECTING
	clear_item(cub);
	return (1);
}

int	renderer(t_cub *cub)
{
	long double	multiplier;

	multiplier = 1.000;
	cub->camera.x = cub->player.pos.x - SCREEN_SIZE_X / 2;

	// update_camera(cub);
	if (cub->camera.x < 0)
		cub->camera.x = 0;
	if (cub->camera.x > CAMERA_END_X)
		cub->camera.x = CAMERA_END_X;
	cub->player.camera.x = PLAYER_POS_X - cub->camera.x;
	cub->player.camera.y = PLAYER_POS_Y;

	(*cub).image.image = mlx_new_image((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*cub).image.addr = mlx_get_data_addr((*cub).image.image, &(*cub).image.bits_per_pixel, &(*cub).image.line_length, &(*cub).image.endian);

	drawtexture(&cub->image, &cub->bckgrnd.sprite, cub->bckgrnd.pos, cub->bckgrnd.scale *= multiplier);
	draw_map(cub);
	draw_items(cub);
	draw_walls(cub);
	drawtexture(&cub->image, &cub->player.sprite, cub->player.camera, 1);

	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image.image, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->image.image);
	return (1);
}

void	game_start(t_cub *cub)
{
	if (cub->game_start == false)
		cub->game_start = true;
}

int	game_loop(t_cub *cub)
{
	update(cub);
	renderer(cub);
	game_start(cub);
	return (1);
}
