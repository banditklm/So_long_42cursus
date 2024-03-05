/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 02:10:42 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:14:49 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	get_lenght(long nb)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = nb * (-1);
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = get_lenght(nb);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (nb < 0)
		nb = -nb;
	while (len >= 0)
	{
		if (n < 0 && len == 0)
		{
			str[len] = '-';
			break ;
		}
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

void	putsteps(t_data *data)
{
	char	*step;

	step = ft_itoa(data->steps);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 90, 18, 0xffffff, step);
	free(step);
}
