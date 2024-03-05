/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:05:16 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/26 21:57:59 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	moves(int keycode, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map->matrix[i])
	{
		j = 0;
		while (data->map->matrix[i][j])
		{
			if (!(move_to(data, keycode, i, j)))
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_destroy_win(t_data *data)
{
	close_window(data, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_map		map;

	(1) && (map.height = 0, map.width = 0, map.map = NULL,
		map.matrix = NULL, data.map = &map, data.steps = 0);
	parser(&map, av, ac);
	data.mlx_ptr = mlx_init();
	if (!(data.mlx_ptr))
		ft_error("mlx fails!", &map, NULL, (&map)->map);
	data.mlx_win = mlx_new_window(data.mlx_ptr,
			map.width * 60, map.height * 60, "so_long");
	if (!(data.mlx_win))
		ft_error("mlx fails!", &map, NULL, (&map)->map);
	mlx_hook(data.mlx_win, 17, 0, ft_destroy_win, &data);
	mlx_hook(data.mlx_win, 2, 0, moves, &data);
	mlx_key_hook(data.mlx_win, key_hook, &data);
	image_init(&data);
	fill_map(data);
	mlx_loop(data.mlx_ptr);
}
