/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/07 13:48:23 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>

int	update(t_cub *cub)
{
	calculate_Delta(cub);
	printf("direction: %f \n", cub->player.direction.x);
	printf("velocity.x: %f \n", cub->player.velocity.x);
	printf("velocity.y: %f \n", cub->player.velocity.y);
	printf("delta: %f \n", cub->delta);
	printf("pos.y: %f \n", cub->player.pos.y);
	printf("pos.x: %f \n", cub->player.pos.x);
	printf("jump_started: %f \n", cub->player.jump.t_started);
	printf("jump_elapsed: %f \n", cub->player.jump.t_elapsed);
	printf("camera.x: %f \n", cub->camera.x);

	// VELOCITY(get_velocity())
	if (cub->player.direction.x != 0)
	{
		cub->player.velocity.x += cub->player.direction.x * 500 * cub->delta;
		if (cub->player.velocity.x >= 200)
			cub->player.velocity.x = 200;
		if (cub->player.velocity.x <= -200)
			cub->player.velocity.x = -200;
	}
	else if (cub->player.direction.x == 0)
		cub->player.velocity.x = 0;

	// FALLING UNTIL FLOOR (check falling())
	if (cub->player.pos.y < SCREEN_SIZE_Y - TILE_SIZE_Y
		&& cub->player.velocity.y == 0
		&& cub->player.jump.active == false)
	{
		cub->player.velocity.y += 20000 * cub->delta;
	}
	if (cub->player.pos.y >= SCREEN_SIZE_Y - TILE_SIZE_Y * 2.9)
		cub->player.velocity.y = 0;
	if ((cub->player.pos.x <= TILE_SIZE_X
		&& cub->player.direction.x == -1)
		|| cub->player.pos.x >= SCREEN_SIZE_X * 6)
		cub->player.velocity.x = 0;

	// JUMPING (check_jump())
	if (cub->player.jump.active == true)
	{
		if (cub->player.velocity.y == 0)
			cub->player.velocity.y = -250;

		if(cub->player.jump.t_started == 0)
			cub->player.jump.t_started = cub->delta;

		cub->player.jump.t_elapsed += cub->delta;
		if (cub->player.velocity.y < 0)
			cub->player.velocity.y *= 0.997f;
		if (cub->player.jump.t_elapsed >= cub->player.jump.duration * 0.90f
			&& cub->player.jump.t_elapsed < cub->player.jump.duration)
			cub->player.velocity.y = -0.4f * cub->delta;
		if (cub->player.jump.t_elapsed >= cub->player.jump.duration)
		{
			cub->player.velocity.y += 25000 * cub->delta;
			cub->player.jump.active = false;
			cub->player.jump.t_started = 0;
			cub->player.jump.t_elapsed = 0;
		}
	}
		

	// MOVEMENT (get_movement())
	cub->player.pos.y += cub->player.velocity.y * cub->delta;
	cub->player.pos.x += cub->player.velocity.x * cub->delta;
	return (1);
}

int	renderer(t_cub *cub)
{
	/*t_point middle_screen;

	middle_screen.x = SCREEN_SIZE_X / 2;
	middle_screen.y = SCREEN_SIZE_Y / 2;*/

	(*cub).image.image = mlx_new_image((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*cub).image.addr = mlx_get_data_addr((*cub).image.image, &(*cub).image.bits_per_pixel, &(*cub).image.line_length, &(*cub).image.endian);

	drawtexture(&cub->image, &cub->bckgrnd, (t_point){00, 00}, 1);
	drawtexture(&cub->image, &cub->player.sprite, cub->player.pos, 1.5);
	draw_map(cub);

	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image.image, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->image.image);
	return (1);
}

int	game_loop(t_cub *cub)
{
	update(cub);
	renderer(cub);
	return (1);
}
