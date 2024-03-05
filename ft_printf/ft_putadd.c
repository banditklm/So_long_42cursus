/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 04:34:42 by kelmounj          #+#    #+#             */
/*   Updated: 2023/12/09 04:34:46 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd(unsigned long n, char *base, int *counter)
{
	unsigned long	nb;

	nb = n;
	if (nb > 15)
		ft_putadd(nb / 16, base, counter);
	(*counter)++;
	ft_putchr(base[nb % 16]);
}
