/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:22:12 by avieira-          #+#    #+#             */
/*   Updated: 2025/07/29 16:17:47 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse(t_game *game, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map_ber");
		return (0);
	}
	return (map_parse(game, argv[1]));
}
