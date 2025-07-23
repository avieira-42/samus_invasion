/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-soeiro <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:14:14 by a-soeiro          #+#    #+#             */
/*   Updated: 2025/07/23 21:26:56 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_attack_timer(t_game *game)
{
	if (ATTACK_TIMER >= 0 && ATTACK_TIMER <= 10)
		ATTACK_TIMER++;
}
