/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:39:19 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/31 17:29:28 by avieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

void	init_map(t_game *game, char *argv1)
{
	game->map.height = 0;
	game->map.width = 0;
	game->map.c_count = 0;
	game->map.p_count = 0;
	game->map.e_count = 0;
	game->map.x_count = 0;
	game->map.text = read_map(argv1);
	if (game->map.text == NULL)
		return ;
}
