/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:01:43 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/07/04 17:15:54 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	calculate_Delta(t_cub *cub)
{
	cub->delta = (get_time() - cub->last_frame_time) / 1000.0f;
	cub->last_frame_time = get_time();
}
