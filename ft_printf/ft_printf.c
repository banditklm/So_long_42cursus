/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:38:40 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:17:24 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_it(char c, char *s)
{
	int	v_bool;
	int	i;

	v_bool = 0;
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			v_bool = 1;
		i++;
	}
	return (v_bool);
}

static int	check_flag(char c, char *s)
{
	int	v_bool;
	int	i;

	v_bool = 0;
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			v_bool = 1;
		i++;
	}
	return (v_bool);
}

static int	put_it(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'c')
		len += ft_putchr(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'u')
		len += ft_putunsnbr(va_arg(args, unsigned int));
	if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", &len);
	if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", &len);
	if (c == 'p')
	{
		len += ft_putchr('0');
		len += ft_putchr('x');
		ft_putadd(va_arg(args, unsigned long), "0123456789abcdef", &len);
	}
	if (c == '%')
		len += ft_putchr('%');
	return (len);
}

static int	set_flag(va_list args, char c, char d)
{
	int		len;
	va_list	__args;

	va_copy(__args, args);
	len = 0;
	if (va_arg(__args, int) >= 0 && c == ' ' && (d == 'd' || d == 'i'))
		len += ft_putchr(' ');
	va_copy(__args, args);
	if (va_arg(__args, int) >= 0 && c == '+' && (d == 'd' || d == 'i'))
		len += ft_putchr('+');
	va_copy(__args, args);
	if (va_arg(__args, unsigned int) != 0 && c == '#' && d == 'x')
	{
		len += ft_putchr('0');
		len += ft_putchr('x');
	}
	va_copy(__args, args);
	if (va_arg(__args, unsigned int) != 0 && c == '#' && d == 'X')
	{
		len += ft_putchr('0');
		len += ft_putchr('X');
	}
	va_end(__args);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = -1;
	len = 0;
	if ((write(1, "", 0)) < 0)
		return (-1);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			while ((check_flag(str[i], "# +") == 1)
				|| (str[i] >= '0' && str[i] <= '9'))
				i++;
			len += set_flag(args, str[i - 1], str[i]);
			if (check_it(str[i], "cspdiuxX%") == 1)
				len += put_it(args, str[i]);
		}
		else
			len += ft_putchr(str[i]);
	}
	return (va_end(args), len);
}
