/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:30 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:34 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"


void	ft_free(t_cub *cub, char *line)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	if (cub && cub->map)
	{
		while (cub->map[i])
			free(cub->map[i++]);
		free(cub->map);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}
