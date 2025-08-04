/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:14:14 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/25 01:36:30 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	update_attack_timer(t_game *game)
{
	if (game->player.attack_timer >= 0 && game->player.attack_timer <= 24)
		game->player.attack_timer++;
}
