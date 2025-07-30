/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:14:14 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/25 01:36:30 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_attack_timer(t_game *game)
{
	if (game->player.attack_timer >= 0 && game->player.attack_timer <= 24)
		game->player.attack_timer++;
}
