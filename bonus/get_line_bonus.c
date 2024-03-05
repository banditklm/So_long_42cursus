/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:12:17 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/16 23:22:46 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*alloc_buf(void)
{
	char	*buff;
	size_t	i;

	buff = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		*(buff + i) = '\0';
		i++;
	}
	*(buff + i) = '\0';
	return (buff);
}

static int	check_new_line(char *res)
{
	int	i;
	int	v_bool;

	i = 0;
	v_bool = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			v_bool = 1;
		i++;
	}
	return (v_bool);
}

static char	*read_buf(int fd, char *res)
{
	char	*buff;
	int		r;

	r = 1;
	while (r > 0)
	{
		buff = alloc_buf();
		if (!buff)
			return (free(res), res = NULL, NULL);
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
			return (free(buff), buff = NULL, NULL);
		if (r == 0)
			return (free(buff), buff = NULL, res);
		res = ft_strjoin_gnl(res, buff);
		free(buff);
		if (!res)
			return (NULL);
		if (check_new_line(res) == 1)
			break ;
	}
	return (res);
}

static char	*get_line(char *static_str)
{
	char	*res;
	size_t	i;

	i = 0;
	while (static_str[i] != '\n' && static_str[i])
		i++;
	if (static_str[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (static_str[i] != '\n' && static_str[i])
	{
		res[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)

{
	static char	*static_str = NULL;
	char		*res;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(static_str), static_str = NULL, NULL);
	static_str = read_buf(fd, static_str);
	if (!static_str || !*static_str)
		return (free(static_str), static_str = NULL, NULL);
	res = get_line(static_str);
	if (!res)
		return (free(static_str), static_str = NULL, NULL);
	if (!*static_str)
		return (free(res), free(static_str), static_str = NULL, NULL);
	tmp = ft_strdup_gnl(static_str + ft_strlen_gnl(res));
	free(static_str);
	static_str = NULL;
	if (!tmp)
		return (free(static_str), static_str = NULL, free(res), NULL);
	static_str = ft_strdup_gnl(tmp);
	if (!static_str)
		return (free(res), free(tmp), tmp = NULL, NULL);
	free(tmp);
	tmp = NULL;
	return (res);
}
