/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:09:52 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:16:55 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h> 
# include <mlx.h>
# include <time.h>
# include "../ft_printf/ft_printf.h"

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

typedef struct s_enemy
{
	void	*enemy0;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*enemy5;
	void	*enemy6;
	void	*enemy7;
	void	*enemy8;
	void	*enemy9;
	void	*enemy10;
	void	*enemy11;
}	t_enemy;

typedef struct s_crystal
{
	void	*crystal1;
	void	*crystal2;
	void	*crystal3;
	void	*crystal4;
}	t_crystal;

typedef struct s_images
{
	void		*wall;
	void		*floor;
	void		*exit;
	void		*exit2;
	void		*coin;
	void		*player;
	t_enemy		enemy;
	t_crystal	crystal;
	void		*steps;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	mlx_img;
	int		width;
	int		height;
	int		steps;
	clock_t	time;
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
char	*ft_itoa(int n);
int		put_animation(t_data *data);
void	putsteps(t_data *data);
void	enemy_image_init(t_data *data);
void	crystal_image_init(t_data *data);
void	put_image_crystal(t_data *data, int frame2, int i, int j);

#endif