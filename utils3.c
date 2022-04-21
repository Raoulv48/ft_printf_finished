/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:52:51 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/19 16:45:23 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_sign_hex(t_flag *flags)
{
	if (flags->hex_bool == 1)
	{
		flags->hexwbool = 1;
		if (flags->width > flags->prec && flags->flag != '-')
			flags->len += 2;
		else
			flags->len -= 2;
		flags->hex_bool = 0;
		ft_putstr_fd(flags->hex, 1, flags);
	}
}

void	set_sign(t_flag *flags)
{
	if (flags->hex_bool == 1)
		set_sign_hex(flags);
	if (flags->bool_sign)
		ft_putchar_fd(flags->sign, 1, flags);
	if (flags->flag == '0' && flags->bool_sign == 1)
		flags->bool_sign = 0;
	if (flags->prec_bool == 1 && flags->bool_sign == 1 && flags->fit == 0)
		flags->bool_sign = 0;
	if (flags->prec_bool && flags->bool_sign == 1 && flags->prec >
		flags->width && flags->width_bool && flags->flag == '-')
	{
		flags->i--;
		flags->bool_sign = 0;
	}
	if (flags->prec_bool && flags->bool_sign == 1 &&
		flags->prec > flags->width && flags->width_bool)
	{
		flags->i -= 2;
		flags->bool_sign = 0;
	}
	if (flags->prec_bool == 1 && flags->bool_sign == 1)
		flags->i--;
	flags->bool_sign = 0;
}
