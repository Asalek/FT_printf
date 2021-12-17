/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xxdicsp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:33:48 by asalek            #+#    #+#             */
/*   Updated: 2021/12/16 00:07:56 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_x_lentgh(unsigned long long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

int	print_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	if (ptr == 0)
		len += write(1, "0", 1);
	else
		len += hexadecimal(ptr, 'x');
	return (len);
}

int	hexadecimal(unsigned long long i, char t)
{
	if (i <= 9)
		ft_putchar(i + 48);
	if (i > 9 && i < 16)
	{
		if (t == 'x')
			ft_putchar(i - 10 + 'a');
		else
			ft_putchar(i - 10 + 'A');
	}
	if (i >= 16)
	{
		hexadecimal(i / 16, t);
		hexadecimal(i % 16, t);
	}
	return (p_x_lentgh(i));
}

void	int_char(char t, int i)
{
	if (t == 'd' || t == 'i')
	{
		ft_putnbr_int(i);
	}
	else if (t == 'c')
	{
		ft_putchar(i);
	}
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
