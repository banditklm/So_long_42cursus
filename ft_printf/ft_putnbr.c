/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:05:36 by kelmounj          #+#    #+#             */
/*   Updated: 2023/12/07 18:05:39 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_lenght(long nb)
{
	int		count;

	count = 1;
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
	return (count);
}

int	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchr('-');
		nb = nb * (-1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = (nb % 10) + 48;
	ft_putchr(nb);
	return (get_lenght(n));
}
