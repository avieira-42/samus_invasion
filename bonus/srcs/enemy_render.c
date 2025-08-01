/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:00:15 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/30 00:25:04 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	position_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = new_enemy(game);
	add_enemy(&game->enemies, enemy);
}
