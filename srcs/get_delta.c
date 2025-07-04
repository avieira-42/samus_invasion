/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:09:20 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/04 17:38:22 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

long long	get_time(void)
{
	struct	timeval	tv;

	gettimeofday(&tv, NULL);
	return((long long)(tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	get_delta(t_game *game)
{
	cub->delta = (get_time() - cub->last_frame_time) / 1000.0f;
	cub->last_frame_time = get_time();
}
