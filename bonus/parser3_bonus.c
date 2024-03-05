/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:16:14 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 02:52:54 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_one(t_map *map)
{
	int		i;

	i = 0;
	while (map->matrix[0][i])
	{
		if (map->matrix[0][i] != '1')
			ft_error("no walls", map, NULL, map->map);
		i++;
	}
	i = 0;
	while (map->matrix[map->height - 1][i])
	{
		if (map->matrix[map->height - 1][i] != '1')
			ft_error("no walls", map, NULL, map->map);
		i++;
	}
	return (1);
}

int	check_rectangle(t_map *map)
{
	int		i;

	i = 0;
	while (map->matrix[0][i])
		i++;
	map->width = i;
	i = 0;
	while (map->matrix[i])
	{
		if (ft_strlen(map->matrix[i]) != map->width)
			ft_error("the map isn't rectangle", map, NULL, map->map);
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int		i;

	i = 0;
	while (map->matrix[i])
	{
		if (map->matrix[i][0] != '1'
			|| map->matrix[i][ft_strlen(map->matrix[i]) - 1] != '1')
			ft_error("no wall!", map, NULL, map->map);
		i++;
	}
	return (1);
}

void	ft_error(char *str_err, t_map *map, char **flood, char *str)
{
	int		i;

	i = 0;
	write(2, "Error :\n", 8);
	while (str_err[i])
	{
		write(2, &str_err[i], 1);
		i++;
	}
	write(2, "\n", 1);
	ft_free(map, flood, str);
	exit(1);
}

void	ft_free(t_map *map, char **flood, char *str)
{
	int	i;

	i = 0;
	if (map && map->matrix)
	{
		while (map->matrix[i])
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	i = 0;
	if (flood)
	{
		while (flood[i])
		{
			free(flood[i]);
			i++;
		}
		free(flood);
	}
	free(str);
}
