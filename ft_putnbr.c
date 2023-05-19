/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoongsu <psoongsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 02:02:15 by psoongsu          #+#    #+#             */
/*   Updated: 2023/05/19 13:13:11 by psoongsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_putnbr(uintptr_t n, uintptr_t base, char *charinset, int *len)
{
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= base)
		ft_putnbr((n / base), base, charinset, len);
	*len += write(1, &charinset[n % base], 1);
}

void	ft_putptr(size_t n, size_t base, char *charinset, int *len)
{
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		ft_putptr((n / base), base, charinset, len);
	*len += write(1, &charinset[n % base], 1);
}

void	ft_putint(int n, int base, char *charinset, int *len)
{
	if (n == -2147483648)
	{
		*len += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		ft_putint((n / base), base, charinset, len);
	*len += write(1, &charinset[n % base], 1);
}
