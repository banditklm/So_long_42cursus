/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:14:10 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/17 00:11:54 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_new_lines(char *str)
{
	int		i;
	int		v_bool;

	i = 0;
	v_bool = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			v_bool = 1;
			break ;
		}
		i++;
	}
	return (v_bool);
}

char	*read_map(char *file)
{
	int		fd;
	char	*buffer;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = get_next_line(fd);
	tmp = NULL;
	while (buffer)
	{
		tmp = ft_strjoin(tmp, buffer);
		free(buffer);
		if (check_new_lines(tmp) != 0)
			ft_error("there is a new line", NULL, NULL, tmp);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (tmp);
}
