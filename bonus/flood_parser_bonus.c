/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:17:06 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/26 21:50:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_pos	get_pos(char **flood)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.p_pos_x = 0;
	pos.p_pos_y = 0;
	while (flood[i])
	{
		j = 0;
		while (flood[i][j])
		{
			if (flood[i][j] == 'P')
			{
				pos.p_pos_x = i;
				pos.p_pos_y = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

static void	flood_fill(char **flood, int pos_x, int pos_y, char c)
{
	if (flood[pos_x - 1][pos_y] == '0' ||
		flood[pos_x - 1][pos_y] == 'C' || flood[pos_x - 1][pos_y] == c)
	{
		flood[pos_x - 1][pos_y] = 'P';
		flood_fill(flood, pos_x - 1, pos_y, c);
	}
	if (flood[pos_x + 1][pos_y] == '0' ||
		flood[pos_x + 1][pos_y] == 'C' || flood[pos_x + 1][pos_y] == c)
	{
		flood[pos_x + 1][pos_y] = 'P';
		flood_fill(flood, pos_x + 1, pos_y, c);
	}
	if (flood[pos_x][pos_y + 1] == '0' ||
		flood[pos_x][pos_y + 1] == 'C' || flood[pos_x][pos_y + 1] == c)
	{
		flood[pos_x][pos_y + 1] = 'P';
		flood_fill(flood, pos_x, pos_y + 1, c);
	}
	if (flood[pos_x][pos_y - 1] == '0' ||
		flood[pos_x][pos_y - 1] == 'C' || flood[pos_x][pos_y - 1] == c)
	{
		flood[pos_x][pos_y - 1] = 'P';
		flood_fill(flood, pos_x, pos_y - 1, c);
	}
}

static int	check_flood_fill(char **flood, int b, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (flood[i])
	{
		j = -1;
		while (flood[i][++j])
		{
			if (b)
			{
				if (flood[i][j] == 'C')
					ft_error("Coin not reached!", map, flood, map->map);
				else if (flood[i][j] == 'E')
					ft_error("Exit not reached!", map, flood, map->map);
			}
			else
			{
				if (flood[i][j] == 'C')
					ft_error("Coin not reached!", map, flood, map->map);
			}
		}
		i++;
	}
	return (1);
}

void	check_flood(char *str, t_map *map)
{
	char	**flood;
	t_pos	pos;

	flood = ft_split(str, '\n');
	pos = get_pos(flood);
	flood_fill(flood, pos.p_pos_x, pos.p_pos_y, 'E');
	check_flood_fill(flood, 1, map);
	ft_free(NULL, flood, NULL);
	flood = ft_split(str, '\n');
	flood_fill(flood, pos.p_pos_x, pos.p_pos_y, 'C');
	check_flood_fill(flood, 0, map);
	ft_free(NULL, flood, NULL);
}
