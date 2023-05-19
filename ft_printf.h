/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoongsu <psoongsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:42:38 by psoongsu          #+#    #+#             */
/*   Updated: 2023/05/19 13:01:09 by psoongsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	<stdarg.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

int			ft_printf(const char *str, ...);
/*funtion*/
void		ft_putnbr(uintptr_t n, uintptr_t base, char *charinset, int*len);
void		ft_putptr(size_t n, size_t base, char *charinset, int *len);
void		ft_putint(int n, int base, char *charinset, int *len);
int			ft_print_str(char *str);
int			ft_print_char(char c);

#endif
