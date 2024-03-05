/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:58:49 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/25 03:57:03 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_right(t_data *data, int i, int j)
{
	if (data->map->matrix[i][j] == 'P' && data->map->matrix[i][j + 1] != '1')
	{
		if (data->map->matrix[i][j + 1] == 'E')
		{
			if (!(is_collect(*data)))
			{
				ft_printf("steps : %d\nyou won!\n", ++(data->steps));
				close_window(data, 0);
			}
		}
		else if (data->map->matrix[i][j + 1] == 'M')
		{
			ft_printf("steps : %d\nyou lost!\n", ++(data->steps));
			close_window(data, 0);
		}
		else
		{
			data->map->matrix[i][j] = '0';
			data->map->matrix[i][j + 1] = 'P';
			ft_printf("steps : %d\n", ++(data->steps));
			fill_map(*data);
		}
		return (1);
	}
	return (0);
}

static int	move_left(t_data *data, int i, int j)
{
	if (data->map->matrix[i][j] == 'P' && data->map->matrix[i][j - 1] != '1')
	{
		if (data->map->matrix[i][j - 1] == 'E')
		{
			if (!(is_collect(*data)))
			{
				ft_printf("steps : %d\nyou won!\n", ++(data->steps));
				close_window(data, 0);
			}
		}
		else if (data->map->matrix[i][j - 1] == 'M')
		{
			ft_printf("steps : %d\nyou lost!\n", ++(data->steps));
			close_window(data, 0);
		}
		else
		{
			data->map->matrix[i][j] = '0';
			data->map->matrix[i][j - 1] = 'P';
			ft_printf("steps : %d\n", ++(data->steps));
			fill_map(*data);
		}
		return (1);
	}
	return (0);
}

static int	move_up(t_data *data, int i, int j)
{
	if (data->map->matrix[i][j] == 'P' && data->map->matrix[i - 1][j] != '1')
	{
		if (data->map->matrix[i - 1][j] == 'E')
		{
			if (!(is_collect(*data)))
			{
				ft_printf("steps : %d\nyou won!\n", ++(data->steps));
				close_window(data, 0);
			}
		}
		else if (data->map->matrix[i - 1][j] == 'M')
		{
			ft_printf("steps : %d\nyou lost!\n", ++(data->steps));
			close_window(data, 0);
		}
		else
		{
			data->map->matrix[i][j] = '0';
			data->map->matrix[i - 1][j] = 'P';
			ft_printf("steps : %d\n", ++(data->steps));
			fill_map(*data);
		}
		return (1);
	}
	return (0);
}

static int	move_down(t_data *data, int i, int j)
{
	if (data->map->matrix[i][j] == 'P' && data->map->matrix[i + 1][j] != '1')
	{
		if (data->map->matrix[i + 1][j] == 'E')
		{
			if (!(is_collect(*data)))
			{
				ft_printf("steps : %d\nyou won!\n", ++(data->steps));
				close_window(data, 0);
			}
		}
		else if (data->map->matrix[i + 1][j] == 'M')
		{
			ft_printf("steps : %d\nyou lost!\n", ++(data->steps));
			close_window(data, 0);
		}
		else
		{
			data->map->matrix[i][j] = '0';
			data->map->matrix[i + 1][j] = 'P';
			ft_printf("steps : %d\n", ++(data->steps));
			fill_map(*data);
		}
		return (1);
	}
	return (0);
}

int	move_to(t_data *data, int keycode, int i, int j)
{
	if (keycode == 2 || keycode == 124)
	{
		if (move_right(data, i, j))
			return (0);
	}
	else if (keycode == 0 || keycode == 123)
	{
		if (move_left(data, i, j))
			return (0);
	}
	else if (keycode == 13 || keycode == 126)
	{
		if (move_up(data, i, j))
			return (0);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (move_down(data, i, j))
			return (0);
	}
	return (1);
}
