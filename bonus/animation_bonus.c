/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:08:14 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:16:48 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_pro(t_data *data)
{
	if (!data->mlx_img.enemy.enemy0 || !data->mlx_img.enemy.enemy1
		|| !data->mlx_img.enemy.enemy2 || !data->mlx_img.enemy.enemy3
		|| !data->mlx_img.enemy.enemy4 || !data->mlx_img.enemy.enemy5
		|| !data->mlx_img.enemy.enemy6 || !data->mlx_img.enemy.enemy7
		|| !data->mlx_img.enemy.enemy8 || !data->mlx_img.enemy.enemy9
		|| !data->mlx_img.enemy.enemy10 || !data->mlx_img.enemy.enemy11)
		close_window(data, 1);
}

void	enemy_image_init(t_data *data)
{
	data->mlx_img.enemy.enemy0 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy00.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy01.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy02.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy03.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy04.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy05.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy6 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy06.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy7 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy07.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy8 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy08.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy9 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy09.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy10 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy10.xpm", &data->width, &data->height);
	data->mlx_img.enemy.enemy11 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy/enemy11.xpm", &data->width, &data->height);
	enemy_pro(data);
}

static void	put_image_2(t_data *data, int frame, int i, int j)
{
	if (frame == 5)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy5, (j * 60) + 9, i * 60);
	if (frame == 6)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy6, (j * 60) + 9, i * 60);
	if (frame == 7)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy7, (j * 60) + 9, i * 60);
	if (frame == 8)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy8, (j * 60) + 9, i * 60);
	if (frame == 9)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy9, (j * 60) + 9, i * 60);
	if (frame == 10)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy10, (j * 60) + 9, i * 60);
	if (frame == 11)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy11, (j * 60) + 9, i * 60);
}

static void	put_image(t_data *data, int frame, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img.floor, j * 60, i * 60);
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy0, (j * 60) + 9, i * 60);
	if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy1, (j * 60) + 9, i * 60);
	if (frame == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy2, (j * 60) + 9, i * 60);
	if (frame == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy3, (j * 60) + 9, i * 60);
	if (frame == 4)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.enemy.enemy4, (j * 60) + 9, i * 60);
	put_image_2(data, frame, i, j);
}

int	put_animation(t_data *data)
{
	static int		frame[2];
	int				i[2];

	(1) && (i[0] = 0, i[1] = -1);
	if (clock() > data->time + 15000)
	{
		while (data->map->matrix[i[0]])
		{
			while (data->map->matrix[i[0]][++i[1]])
			{
				if (data->map->matrix[i[0]][i[1]] == 'M')
					put_image(data, frame[0], i[0], i[1]);
				if (data->map->matrix[i[0]][i[1]] == 'C')
					put_image_crystal(data, frame[1], i[0], i[1]);
			}
			(1) && (i[0]++, i[1] = -1);
		}
		data->time = clock();
		(1) && (frame[0]++, frame[1]++);
	}
	if (frame[0] == 12)
		frame[0] = 0;
	if (frame[1] == 4)
		frame[1] = 0;
	return (0);
}
