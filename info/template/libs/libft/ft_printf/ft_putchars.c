/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:21:14 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 16:45:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putcharmod(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstrmod(const char *str)
{
	int	i;

	if (!str)
		return (ft_putstrmod("(null)"));
	i = 0;
	while (*str)
	{
		i += ft_putcharmod(*str);
		str++;
	}
	return (i);
}
