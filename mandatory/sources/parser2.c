/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:52:04 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/16 02:45:45 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	check_characters(char *str)
{
	int		i;
	int		c;
	int		e;
	int		p;

	(1) && (i = 0, c = 0, e = 0, p = 0);
	while (str[i])
	{
		if (str[i] == 'C')
			c++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		i++;
	}
	if (c <= 0)
		ft_error("no coins to collect!", NULL, NULL, str);
	if (e != 1)
		ft_error("must one Exit!", NULL, NULL, str);
	if (p != 1)
		ft_error("must one player!", NULL, NULL, str);
	return (1);
}

static int	check_newline(char *str)
{
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		ft_error("the map must start & end by one", NULL, NULL, str);
	else
		return (1);
	return (0);
}

static	int	check_if_non_char(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1'
			&& str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != '\n')
			ft_error("there is an unknown character!", NULL, NULL, str);
		i++;
	}
	return (1);
}

char	*check_and_split(t_map *map, char *file)
{
	char	*str;

	str = read_map(file);
	if (!str)
	{
		ft_error("no map!", NULL, NULL, NULL);
		map->matrix = NULL;
	}
	else
	{
		if (!check_newline(str))
			exit(1);
		if (!check_characters(str))
			exit(1);
		if (!check_if_non_char(str))
			exit(1);
		map->matrix = ft_split(str, '\n');
		return (str);
	}
	return (NULL);
}
