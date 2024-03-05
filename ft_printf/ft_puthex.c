/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:13:01 by kelmounj          #+#    #+#             */
/*   Updated: 2023/12/08 22:13:03 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *base, int *counter)
{
	long	nb;

	nb = n;
	if (nb > 15)
		ft_puthex(nb / 16, base, counter);
	(*counter)++;
	ft_putchr(base[nb % 16]);
}
