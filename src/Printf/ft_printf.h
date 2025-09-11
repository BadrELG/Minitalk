/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:39:27 by bael-gho          #+#    #+#             */
/*   Updated: 2025/09/11 04:13:07 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>

int	ft_puthex(char c, unsigned long n);
int	ft_putpercent(void);
int	ft_conv(char c, va_list args);
int	ft_putptr(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);

#endif