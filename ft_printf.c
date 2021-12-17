/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:28:48 by asalek            #+#    #+#             */
/*   Updated: 2021/12/16 00:08:27 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
		i += ft_putchar(*str++);
	return (i);
}

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i += write(1, "(null)", 6);
	else
		i += ft_putstr(str);
	return (i);
}

int	ft_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		length += print_string(va_arg(args, char *));
	else if (format == 'p')
		length += print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		length += nbrlen(va_arg(args, int));
	else if (format == 'u')
		length += ft_putnbr_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += hexadecimal(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
