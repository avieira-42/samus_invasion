/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/08 05:12:11 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>
int	update(t_cub *cub) {
	calculate_Delta(cub);
	printf("direction: %f \n", cub->player.direction.x);
	printf("velocity.x: %f \n", cub->player.velocity.x);
	printf("delta: %f \n", cub->delta); printf("pos.y: %f \n", cub->player.pos.y);
	printf("pos.x: %f \n", cub->player.pos.x);
	printf("jump_started: %f \n", cub->player.jump.t_started);
	printf("jump_elapsed: %f \n", cub->player.jump.t_elapsed);
	printf("camera.x: %f \n", cub->camera.x);
	printf("velocity.y: %f \n", cub->player.velocity.y);

	//INIT VELOCITY_X
	PLAYER_VEL_X = VELOCITY_X;


	// SCREEN LIMITS is_play_area()
	if ((PLAYER_POS_X <= TILE_SIZE_Y && PLAYER_DIR_X == -1)
		|| (PLAYER_POS_X >= SCREEN_END_X && PLAYER_DIR_X == 1))
		PLAYER_VEL_X = 0;


	// JUMPING (check_jump())
	if (cub->player.jump.active == true)
	{

		if (PLAYER_POS_Y >= SCREEN_SIZE_Y - TILE_SIZE_Y * 3.75
			&& cub->player.jump.t_started > 0)
		{
			cub->player.jump.active = false;
			cub->player.jump.t_elapsed = 0;
			cub->player.jump.t_started = 0;
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
	if (PLAYER_POS_Y < SCREEN_SIZE_Y - TILE_SIZE_Y
		&& cub->player.jump.active == false)
	{
		JUMP_VEL = -VELOCITY_Y;
	}
	if (PLAYER_POS_Y >= SCREEN_SIZE_Y - TILE_SIZE_Y * 3.75
		&& cub->player.jump.active == false )
	{
		PLAYER_POS_Y = SCREEN_SIZE_Y - TILE_SIZE_Y * 3.75;
		JUMP_VEL = 0;
	}

	//INIT VELOCITY (vel_init())
	PLAYER_VEL_Y = JUMP_VEL + GRAVITY * cub->player.jump.t_elapsed;

	// MOVEMENT (get_movement())
	PLAYER_POS_Y += PLAYER_VEL_Y * DELTA_T;
	PLAYER_POS_X += PLAYER_DIR_X * PLAYER_VEL_X * DELTA_T;
	return (1);
}

int	renderer(t_cub *cub)
{
	cub->camera.x = cub->player.pos.x - SCREEN_SIZE_X / 2;

	// update_camera(cub);
	if (cub->camera.x < 0)
		cub->camera.x = 0;
	if (cub->camera.x > 4129)
		cub->camera.x = 4129;
	cub->player.camera.x = PLAYER_POS_X - cub->camera.x;
	cub->player.camera.y = PLAYER_POS_Y;

	(*cub).image.image = mlx_new_image((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*cub).image.addr = mlx_get_data_addr((*cub).image.image, &(*cub).image.bits_per_pixel, &(*cub).image.line_length, &(*cub).image.endian);

	drawtexture(&cub->image, &cub->bckgrnd.sprite, cub->bckgrnd.pos, 1);
	draw_map(cub);
	drawtexture(&cub->image, &cub->player.sprite, cub->player.camera, 1.5);

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
