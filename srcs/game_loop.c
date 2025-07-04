/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:24:54 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 23:33:58 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	update(t_game *game)
{
	get_delta(game);

	if (game->player.direction.x != 0)
		game->player.velocity.x = game->player.direction.x * 100 * game->delta;
	if (game->player.direction.y != 0)
		game->player.velocity.y = game->player.direction.y * 100 * game->delta;
}
