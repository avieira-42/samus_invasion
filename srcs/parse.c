/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:22:12 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/06 12:03:21 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_file_name_valid(char *file_name)
{
	while (*file_name)
		file_name++;
	file_name -= 4;
	if (ft_strcmp(file_name, ".ber") != 0)
		return (0);
	if (*(file_name - 1) == '/')
		return (0);
	return (1);
}

int	parse(t_game *game, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map_ber");
		return (0);
	}
	if (!is_file_name_valid(argv[1]))
		return (0);
	return (map_parse(game, argv[1]));
}
