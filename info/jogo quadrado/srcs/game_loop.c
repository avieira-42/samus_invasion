/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:06:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/06/27 15:28:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	update(t_cub *cub)
{
	calculate_Delta(cub);
	//ft_printf("%d, \n", cub->player.direction.x);

	if (cub->player.direction.x != 0)
		cub->player.velocity.x += cub->player.direction.x *  100 * cub->delta;
	else if (cub->player.direction.x == -1)
	{
		cub->player.velocity.x -=  100 * cub->delta;
	}

	if (cub->player.pos.y < SCREEN_SIZE_Y - 30 )
	{
		cub->player.velocity.y += GRAVITY * cub->delta;
	}
	else
	{
		if (cub->player.velocity.y < -0.05)
			cub->player.velocity.y = 0;
		cub->player.velocity.y = -cub->player.velocity.y * 0.8;

	}
	if (cub->player.jump)
	{
		cub->player.velocity.y = -200;
		cub->player.jump = false;
	}

	if (cub->player.pos.x <= 0)
	{
		cub->player.velocity.x = -cub->player.velocity.x;
	}
	if (cub->player.pos.x >= SCREEN_SIZE_X - 30)
	{
		cub->player.velocity.x = -cub->player.velocity.x;
	}

	cub->player.pos.x += cub->player.velocity.x * cub->delta;
	cub->player.pos.y += cub->player.velocity.y * cub->delta;
	return (1);
}

int	renderer(t_cub *cub)
{
	(*cub).image.img = mlx_new_image((*cub).mlx_ptr, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	(*cub).image.addr = mlx_get_data_addr((*cub).image.img, &(*cub).image.bits_per_pixel, &(*cub).image.line_length, &(*cub).image.endian);

	t_point middle_screen;
	middle_screen.x = SCREEN_SIZE_X / 2;
	middle_screen.y = SCREEN_SIZE_Y / 2;
	drawrect(&cub->image, cub->player.pos, (t_point){30, 30}, 0xFFFFFFF);

	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->image.img, 0, 0);
	mlx_destroy_image(cub->mlx_ptr, cub->image.img);
	return (1);
}

int	game_loop(t_cub *cub)
{
	update(cub);
	renderer(cub);
	return (1);
}
