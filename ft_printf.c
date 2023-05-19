/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoongsu <psoongsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:42:26 by psoongsu          #+#    #+#             */
/*   Updated: 2023/05/19 13:00:47 by psoongsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_format(const char *str, va_list ap, int *len, int i)
{
	if (str[i] == 'c')
		*len += ft_print_char((va_arg(ap, int)));
	else if (str[i] == 's')
		*len += ft_print_str(va_arg(ap, char *));
	else if (str[i] == 'p')
	{
		*len += write(1, "0x", 2);
		ft_putptr(va_arg(ap, uintptr_t), 16, "0123456789abcdef", len);
	}
	else if (str[i] == 'd')
		ft_putint(va_arg(ap, int), 10, "0123456789", len);
	else if (str[i] == 'i')
		ft_putint(va_arg(ap, int), 10, "0123456789", len);
	else if (str[i] == 'u')
		ft_putnbr(va_arg(ap, unsigned int), 10, "0123456789", len);
	else if (str[i] == 'x')
		ft_putnbr(va_arg(ap, unsigned int), 16, "0123456789abcdef", len);
	else if (str[i] == 'X')
		ft_putnbr(va_arg(ap, unsigned int), 16, "0123456789ABCDEF", len);
	else if (str[i] == '%')
		*len += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		va;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(va, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
			i = ft_format(str, va, &len, i + 1);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(va);
	return (len);
}
