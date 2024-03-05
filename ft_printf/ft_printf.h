/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:41:24 by kelmounj          #+#    #+#             */
/*   Updated: 2024/02/27 03:17:27 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchr(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putunsnbr(unsigned int n);
void	ft_puthex(unsigned int n, char *base, int *counter);
void	ft_putadd(unsigned long n, char *base, int *counter);

#endif