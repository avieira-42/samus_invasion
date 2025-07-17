/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:23:28 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/01/11 16:46:47 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_freesplit(char **array, int i)
{
	while (i > 0)
	{
		free(array[--i]);
	}
	free(array);
	return (NULL);
}

static int	while_separator(const char *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (words);
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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		arrnmb;
	char	**array;
	int		words;

	words = ft_countwords(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	arrnmb = 0;
	while (s[i] && arrnmb < words)
	{
		i = while_separator(s, c, i);
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		array[arrnmb++] = ft_strndupmod(s, i, j - 1);
		if (!array[arrnmb - 1])
			return (ft_freesplit(array, arrnmb));
		i = j;
	}
	array[arrnmb] = NULL;
	return (array);
}
