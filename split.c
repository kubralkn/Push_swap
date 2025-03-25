/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:31 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 12:00:35 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	count = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_charcount(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	str = malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[++i] = malloc(sizeof(char) * (ft_charcount(s, c) + 1));
			if (!str[i])
				return (free_split(str));
			j = 0;
			while (*s && *s != c)
				str[i][j++] = *s++;
			str[i][j] = '\0';
		}
	}
	str[++i] = NULL;
	return (str);
}
