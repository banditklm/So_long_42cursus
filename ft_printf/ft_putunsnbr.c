/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:54:12 by kelmounj          #+#    #+#             */
/*   Updated: 2023/12/08 10:54:15 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	get_lenght(long nb)
{
	int		count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_putunsnbr(unsigned int n)
{
	long	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	nb = (nb % 10) + 48;
	ft_putchr(nb);
	return (get_lenght(n));
}
