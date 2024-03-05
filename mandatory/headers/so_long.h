/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:49:20 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:17:08 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h> 
# include <mlx.h>
# include "../../ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_map
{
	char	*map;
	char	**matrix;
	int		height;
	int		width;
}	t_map;

typedef struct s_pos
{
	int		p_pos_x;
	int		p_pos_y;
}	t_pos;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*coin;
	void	*player;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	mlx_img;
	int		width;
	int		height;
	int		steps;
	t_map	*map;
}	t_data;

char	*get_next_line(int fd);	
size_t	ft_strlen_gnl(const	char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen(char	*str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	parser(t_map *map, char **av, int ac);
void	check_input(char *file);
char	*read_map(char *file);
void	get_height(char *file, t_map *map);
char	*check_and_split(t_map *map, char *file);
int		check_one(t_map *map);
int		check_rectangle(t_map *map);
int		check_walls(t_map *map);
void	check_flood(char *str, t_map *map);
void	ft_free(t_map *map, char **flood, char *str);
void	ft_error(char *str_err, t_map *map, char **flood, char *str);
int		close_window(t_data *data, int bool);
int		key_hook(int keycode, t_data *data);
void	image_init(t_data *data);
void	fill_map(t_data data);
int		is_collect(t_data data);
int		move_to(t_data *data, int keycode, int i, int j);

#endif
