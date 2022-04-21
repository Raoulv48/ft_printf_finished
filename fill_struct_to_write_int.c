/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct_to_write_int.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 13:06:59 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/16 20:17:03 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_1_0_for_int(t_flag *flags, int data)
{
	flags->len = getintlen(data);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->high = (flags->width >= flags->prec) ? flags->width : flags->prec;
	flags->high = (flags->high >= flags->len) ? flags->high : flags->len;
	flags->bb_var = (flags->high >= flags->len || flags->prec > flags->len)
		? 1 : 0;
	flags->write_left = (flags->flag == '-') ? 1 : 0;
	flags->ba_var = (flags->len < flags->high) ? 1 : 0;
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->bool_sign = (flags->sign == '-' || flags->sign == '+') ? 1 : 0;
	flags->fit = (flags->len <= flags->prec) ? 1 : 0;
	if (flags->sign != '\0' && flags->prec == flags->high)
		flags->counter++;
	flags->towrite = (flags->len > flags->prec && flags->prec_bool == 1)
		? ' ' : flags->towrite;
}

void	before_var(t_flag *flags, int data)
{
	set_1_0_for_int(flags, data);
	write_before_int(flags);
}

void	write_var_zero_prec(t_flag *flags)
{
	if (flags->flag == '-')
	{
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1, flags);
		ft_putchar_fd(' ', 1, flags);
	}
	else if (flags->flag != '-')
	{
		if (flags->width > 0)
			ft_putchar_fd(' ', 1, flags);
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1, flags);
	}
}

void	write_var(t_flag *flags, int data)
{
	if (flags->prec_bool == 1 && flags->prec == 0 && data == 0)
	{
		write_var_zero_prec(flags);
		if (data == 0 && flags->width == 0)
			flags->high = 0;
	}
	else if (flags->bool_sign == 1)
	{
		ft_putchar_fd(flags->sign, 1, flags);
		ft_putnbr_fd(data, 1, flags);
	}
	else
		ft_putnbr_fd(data, 1, flags);
}

void	fill_struct_to_write_int(t_flag *flags, int data)
{
	before_var(flags, data);
	write_var(flags, data);
	if (flags->ba_var == 1 && flags->write_left == 1)
		write_after_int(flags);
}
