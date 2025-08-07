/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira- <avieira-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:22:12 by avieira-          #+#    #+#             */
/*   Updated: 2025/08/07 19:30:34 by a-soeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_includes/so_long_bonus.h"

int	error_message(char *message, int error_code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	return (error_code);
}

int	is_file_name_valid(char *file_name)
{
	while (*file_name)
		file_name++;
	file_name -= 4;
	if (ft_strcmp(file_name, ".ber"))
		return (error_message("file type must be .ber\n", 0));
	if (*(file_name - 1) == '/')
		return (error_message("file cannot be hidden/unamed\n", 0));
	return (1);
}

int	parse(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		return (error_message("Usage: ./so_long *.ber\n", 0));
	if (!map_parse(game, argv[1]))
		return (0);
	if (!is_file_name_valid(argv[1]))
		return (0);
	return (1);
}
