/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:01:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/30 00:16:36 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	calculate_delta(t_game *game)
{
	game->delta = (get_time() - game->last_frame_time) / 1000.0f;
	game->last_frame_time = get_time();
}
