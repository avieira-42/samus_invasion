/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:55:04 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/03/08 18:17:09 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*copystr(char *str);
static char	*trimstr(char *str);
static char	*ft_strndupmod(const char *str, int start, int end);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd == -1 && buffer)
			free(buffer);
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = copystr(buffer);
	if (!line)
		return (NULL);
	buffer = trimstr(buffer);
	return (line);
}

static char	*copystr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0' && i > 0)
		--i;
	return (ft_strndupmod(str, 0, i));
}

static char	*trimstr(char *str)
{
	int		str_size;
	int		i;
	char	*result;

	i = 0;
	str_size = ft_strlen(str) - 1;
	while (str[i] != '\n' && str[i + 1])
		i++;
	++i;
	if (!str[i])
		result = NULL;
	else
		result = ft_strndupmod(str, i, str_size);
	free(str);
	return (result);
}

static char	*ft_strndupmod(const char *str, int start, int end)
{
	char	*newstr;
	int		i;
	int		total_len;

	i = 0;
	total_len = end - start + 1;
	newstr = (char *)malloc(total_len + 1);
	if (!newstr)
		return (NULL);
	while (i < total_len)
	{
		newstr[i] = str[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}
