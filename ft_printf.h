/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:37:35 by asalek            #+#    #+#             */
/*   Updated: 2021/12/16 00:10:29 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Libraries

# include<string.h>
# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>
# include<limits.h>
# include<stdlib.h>

//functions :

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		print_string(char *str);
int		ft_format(va_list args, const char format);
int		ft_printf(const char *format, ...);
int		p_x_lentgh(unsigned long long nbr);
int		print_pointer(unsigned long long ptr);
int		hexadecimal(unsigned long long i, char t);
int		ft_printpercent(void);
int		nbrlen(long d);
void	ft_putnbr_int(int i);
int		unbrlen(unsigned int d);
int		ft_putnbr_uint(unsigned int i);

#endif
