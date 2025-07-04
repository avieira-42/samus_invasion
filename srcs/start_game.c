/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:58:42 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 18:05:45 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	start_game(t_game *game)
{
	game->fd = 0;
	game->delta = 0;
	game->last_grame_time = get_time();
	game->player.direction.x = 0;
	game->player.direction.y = 0;
	game->player.pos.x = SCREEN_HEIGHT / 2;
	game->player.pos.y = SCREEN_WIDTH / 2;
	game->player.jump = false;
	game->player.dash = false;
	game->player.slash = false;
	game->player.projectile = false;
	game->player.velocity.x = 0;
	game->player.velocity.y = 0;
}
