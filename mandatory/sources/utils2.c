/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:07:08 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/16 02:31:50 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static	size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

static	int	count_words(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static	int	ft_getlen(const char *src, char c)
{
	int	i;

	i = 0;
	while (*(src + i) != c && *(src + i) != '\0')
		i++;
	return (i);
}

static	char	**fill(char **res, char *s, char c, int i)
{
	int	j;

	j = 0;
	while (*(s + j))
	{
		while (*(s + j) == c)
			j++;
		if (*(s + j))
		{
			res[i] = (char *)malloc(ft_getlen((s + j), c) + 1);
			if (!res[i])
			{
				while (i > 0)
					free(res[--i]);
				free(res);
				return (NULL);
			}
			ft_strlcpy(*(res + i), s + j, ft_getlen((s + j), c) + 1);
			i++;
			j += ft_getlen((s + j), c);
		}
	}
	*(res + i) = NULL;
	return (res);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(8 * (count_words((char *)s, c) + 1));
	if (!res)
		return (NULL);
	res = fill(res, s, c, i);
	return (res);
}
