/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by avieira-          #+#    #+#             */
/*   Updated: 2025/11/27 04:39:46 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"
#include "../rendering.h"

void	position_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = new_enemy(game);
	add_enemy(&game->enemies, enemy);
}
