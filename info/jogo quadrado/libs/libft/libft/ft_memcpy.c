/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:16:09 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 16:46:20 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_bytes;
	unsigned char	*dest_bytes;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (dest);
	src_bytes = (unsigned char *)src;
	dest_bytes = (unsigned char *)dest;
	while (i < n)
	{
		dest_bytes[i] = src_bytes[i];
		i++;
	}
	dest = (((void *)dest_bytes));
	return (dest);
}
