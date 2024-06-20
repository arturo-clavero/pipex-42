/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:06:25 by artclave          #+#    #+#             */
/*   Updated: 2024/01/08 05:14:03 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_if_error(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

char	*malloc_each_str(char const *s, int i, char c)
{
	int		len;
	int		j;
	char	*ptr;

	len = 0;
	j = i;
	while (s[j] && s[j] != c)
	{
		j++;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s[i], len + 1);
	return (ptr);
}

char	**divide_strs(char **ptr, int str_count, const char *s, char c)
{
	int	i;
	int	str_n;

	i = 0;
	str_n = 0;
	while (s[i] && str_n < str_count)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[str_n] = malloc_each_str(s, i, c);
			if (!ptr[str_n])
			{
				free_if_error(ptr, str_n);
				return (NULL);
			}
			str_n++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	ptr[str_n] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		str_count;
	char	**ptr;

	if (!s)
		return (NULL);
	i = 0;
	str_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			str_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	ptr = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!ptr)
		return (NULL);
	ptr = divide_strs(ptr, str_count, s, c);
	if (!ptr)
		return (NULL);
	return (ptr);
}
