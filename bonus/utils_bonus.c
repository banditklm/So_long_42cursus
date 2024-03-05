/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:43:06 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/26 23:31:04 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strlen(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	len;

	if (!s1)
		s1 = ft_strdup_gnl("");
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	return (free(s1), s1 = NULL, str[i] = '\0', str);
}

int	is_collect(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map->matrix[i])
	{
		j = 0;
		while (data.map->matrix[i][j])
		{
			if (data.map->matrix[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_height(char *file, t_map *map)
{
	int		i;
	char	*buffer;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error", NULL, NULL, NULL);
	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		++i;
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	map->height = i;
}

int	close_window(t_data *data, int bool)
{
	ft_free(data->map, NULL, data->map->map);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(bool);
}
