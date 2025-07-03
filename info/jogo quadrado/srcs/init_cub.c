/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:20 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/06/27 15:14:42 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	cub_init(t_cub *cub)
{
	cub->fd = 0;
	cub->delta = 0;
	cub->last_frame_time = get_time();
	cub->player.direction.x = 0;
	cub->player.direction.y = 0;
	cub->player.pos.x  = SCREEN_SIZE_X / 2;
	cub->player.pos.y = SCREEN_SIZE_Y / 2;
	cub->player.jump = false;
	cub->player.velocity.x = 0;
	cub->player.velocity.y = 0;
}
