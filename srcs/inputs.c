/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:44:27 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 23:06:24 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_pressed(int key, t_game *game)
{
	if (key == ESC)
		close_game(game);
	if (key == W || key == U_ARROW)
		game->player.direction.y += 1;
	if (key == S || key == D_ARROW)
		game->player.direction.y += -1;
	if (key == A || key == L_ARROW)
		game->player.direction.x +=	-1;
	if (key == D || key == R_ARROW)
		game->player.direction.x += 1;
	if (key == SPACE)
		cub->player.jump = true;
	if (key == SHIFT)
		cub->player.dash = true;
	if (key == Q)
		cub->player.projectile = true;
	if (key == E)
		cub->player.attack = true;
	return (1);
}

int	key_released(int key_symb, t_game *game)
{
	if (key == W || key == U_ARROW)
		game->player.direction.y += -1;
	if (key == S || key == D_ARROW)
		game->player.direction.y += 1;
	if (key == A || key == L_ARROW)
		game->player.direction.x += 1;
	if (key == D || key == R_ARROW)
		game->player.direction.x += -1;
	return (1);
}
