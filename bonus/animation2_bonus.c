/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:25:31 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/25 03:55:32 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	crystal_image_init(t_data *data)
{
	data->mlx_img.crystal.crystal1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/crystal/crystal0.xpm", &data->width, &data->height);
	data->mlx_img.crystal.crystal2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/crystal/crystal1.xpm", &data->width, &data->height);
	data->mlx_img.crystal.crystal3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/crystal/crystal2.xpm", &data->width, &data->height);
	data->mlx_img.crystal.crystal4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/crystal/crystal3.xpm", &data->width, &data->height);
	if (!data->mlx_img.crystal.crystal1 || !data->mlx_img.crystal.crystal2
		|| !data->mlx_img.crystal.crystal3 || !data->mlx_img.crystal.crystal4)
		close_window(data, 1);
}

void	put_image_crystal(t_data *data, int frame2, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->mlx_img.floor, j * 60, i * 60);
	if (frame2 == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.crystal.crystal1, (j * 60) + 10, (i * 60) + 5);
	if (frame2 == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.crystal.crystal2, (j * 60) + 10, (i * 60) + 5);
	if (frame2 == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.crystal.crystal3, (j * 60) + 10, (i * 60) + 5);
	if (frame2 == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->mlx_img.crystal.crystal4, (j * 60) + 10, (i * 60) + 5);
}
