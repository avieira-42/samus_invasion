/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:59:27 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 17:06:59 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcpy(char *dest, char *src);
static int	new_line(char *str);
static char	*ft_newstrjoin(char *s1, char *s2);

char	*ft_read(int fd, char *next_line)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(next_line), NULL);
	bytes_read = 1;
	while (!new_line(next_line) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && !next_line))
			return (free(buffer), free(next_line), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_newstrjoin(next_line, buffer);
		if (!temp)
			return (free(buffer), free(next_line), NULL);
		free(next_line);
		next_line = temp;
	}
	return (free(buffer), next_line);
}

static int	new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_newstrjoin(char *s1, char *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	str = (char *)malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_strcpy(str, (char *)s1);
	if (s2)
		ft_strcpy((str + s1len), (char *)s2);
	return (str);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
