/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:07:08 by asalek            #+#    #+#             */
/*   Updated: 2021/12/16 00:09:30 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbrlen(long d)
{
	int	len;

	len = 0;
	if (d <= 0)
		len += 1;
	ft_putnbr_int(d);
	while (d != 0)
	{
		d = d / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_int(int i)
{
	if (i < 0 && i > -2147483648)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i == -2147483648)
		ft_putstr("-2147483648");
	if (i >= 0 && i <= 9)
		ft_putchar(i + 48);
	if (i > 9)
	{
		ft_putnbr_int(i / 10);
		ft_putnbr_int(i % 10);
	}
}

int	unbrlen(unsigned int d)
{
	int	len;

	len = 0;
	if (d == 0)
		len += 1;
	while (d != 0)
	{
		d = d / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_uint(unsigned int i)
{
	if (i <= 9)
		ft_putchar(i + 48);
	if (i > 9)
	{
		ft_putnbr_uint(i / 10);
		ft_putnbr_uint(i % 10);
	}
	return (unbrlen(i));
}
