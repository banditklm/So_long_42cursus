/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 22:17:13 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/25 10:07:13 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		write(1, "Exit\n", 5);
		close_window(data, 0);
	}
	return (0);
}

void	image_init(t_data *data)
{
	data->mlx_img.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &data->width, &data->height);
	data->mlx_img.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/door.xpm", &data->width, &data->height);
	data->mlx_img.player = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/anime_xpm/aizen.xpm", &data->width, &data->height);
	data->mlx_img.floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/floor.xpm", &data->width, &data->height);
	data->mlx_img.coin = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/collect.xpm", &data->width, &data->height);
	if (!data->mlx_img.wall || !data->mlx_img.exit || !data->mlx_img.player
		|| !data->mlx_img.floor || !data->mlx_img.coin)
		close_window(data, 1);
}

void	put_image1(t_data data, int i, int j)
{
	if (data.map->matrix[i][j] == '1')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.floor, j * 60, i * 60);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.wall, (j * 60) + 12, i * 60);
	}
	if (data.map->matrix[i][j] == '0')
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.floor, j * 60, i * 60);
	if (data.map->matrix[i][j] == 'C')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.floor, j * 60, i * 60);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.coin, (j * 60) + 10, (i * 60) + 15);
	}
}

void	put_image2(t_data data, int i, int j)
{
	if (data.map->matrix[i][j] == 'E')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.floor, j * 60, i * 60);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.exit, (j * 60) + 12, i * 60);
	}
	if (data.map->matrix[i][j] == 'P')
	{
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.floor, j * 60, i * 60);
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win,
			data.mlx_img.player, (j * 60) + 12, i * 60);
	}
}

void	fill_map(t_data data)
{
	int		i;
	int		j;

	i = 0;
	while (data.map->matrix[i])
	{
		j = 0;
		while (data.map->matrix[i][j])
		{
			put_image1(data, i, j);
			put_image2(data, i, j);
			j++;
		}
		i++;
	}
}
