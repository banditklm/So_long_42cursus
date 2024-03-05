/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:13:39 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 02:33:12 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_strlen_inp(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char)s1[i] || (unsigned char)s2[i])
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i == n)
		return (0);
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

void	check_input(char *file)
{
	if ((ft_strlen_inp(file) < 4
			|| ft_strncmp(file + ft_strlen_inp(file) - 4, ".ber", 4) != 0)
		|| open(file, O_RDONLY) < 0)
		ft_error("invalid input!", NULL, NULL, NULL);
}

void	parser(t_map *map, char **av, int ac)
{
	if (ac < 2)
	{
		write(2, "too few arguments\n", 18);
		exit (1);
	}
	else if (ac > 2)
	{
		write(2, "too many arguments\n", 19);
		exit (1);
	}
	else
	{
		check_input(av[1]);
		get_height(av[1], map);
		if (map->height < 3)
			ft_error("map too short", NULL, NULL, NULL);
		map->map = check_and_split(map, av[1]);
		check_one(map);
		check_rectangle(map);
		check_walls(map);
		check_flood(map->map, map);
	}
}
