/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct_to_write_hex.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 19:05:08 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/16 20:17:07 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_1_0_for_hex(t_flag *flags, unsigned long data)
{
	flags->len = hex_length(data, 16);
	flags->len = (flags->len == 0) ? flags->len + 1 : flags->len;
	flags->len = (flags->sign != '\0') ? flags->len + 1 : flags->len;
	flags->len = (flags->hex_bool == 1 && flags->len > 0)
		? flags->len += 2 : flags->len;
	flags->hex_bool = (data > 0 || flags->convr == 'p') ? flags->hex_bool : 0;
	flags->high = (flags->width >= flags->prec) ? flags->width : flags->prec;
	flags->high = (flags->high >= flags->len) ? flags->high : flags->len;
	flags->bb_var = (flags->high > flags->len || flags->prec > flags->len)
		? 1 : 0;
	flags->write_left = (flags->flag == '-') ? 1 : 0;
	flags->ba_var = (flags->len < flags->high) ? 1 : 0;
	flags->towrite = (flags->flag == '0' || flags->prec_bool == 1) ? '0' : ' ';
	flags->bool_sign = (flags->sign == '-' || flags->sign == '+') ? 1 : 0;
	flags->fit = (flags->len > flags->prec) ? 0 : 1;
	flags->towrite = (flags->len > flags->prec && flags->prec_bool == 1)
		? ' ' : flags->towrite;
	flags->hex = (flags->convr == 'x' || flags->convr == 'p') ? "0x" : "0X";
}

void	write_hex_zero_prec(t_flag *flags)
{
	if (flags->flag == '-')
	{
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1, flags);
		ft_putchar_fd(' ', 1, flags);
	}
	else if (flags->flag != '-')
	{
		if (flags->width > 0 && flags->convr != 'p')
			ft_putchar_fd(' ', 1, flags);
		if (flags->width > flags->len && flags->convr == 'p')
			ft_putchar_fd(' ', 1, flags);
		if (flags->bool_sign == 1)
			ft_putchar_fd(flags->sign, 1, flags);
		else if (flags->hex_bool == 1)
		{
			flags->hexwbool = 1;
			flags->high = (flags->width > 0) ? flags->width : 0;
			ft_putstr_fd(flags->hex, 1, flags);
		}
	}
}

void	write_hex(t_flag *flags, unsigned long data)
{
	int		i;

	i = hex_length(data, 16);
	if (flags->prec_bool == 1 && flags->prec == 0 && data == 0)
		write_hex_zero_prec(flags);
	else
	{
		if (flags->hex_bool == 1 && data > 0)
			ft_putstr_fd(flags->hex, 1, flags);
		if (data == 0)
		{
			if (flags->hex_bool == 1)
			{
				ft_putstr_fd(flags->hex, 1, flags);
				flags->hexwbool = 1;
			}
			ft_putnbr_fd(data, 1, flags);
			flags->printed = 1;
		}
		else
			ft_fillstring(data, 16, i, flags);
	}
}

void	write_after_int(t_flag *flags)
{
	flags->i = (flags->len > flags->prec) ? flags->len : flags->prec;
	if (flags->sign != '\0' && flags->width > flags->prec && flags->prec_bool
		&& flags->fit == 1)
		flags->i++;
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
		flags->i++;
	while (flags->i < flags->high)
	{
		ft_putchar_fd(' ', 1, flags);
		flags->i++;
	}
}

void	fill_struct_to_write_hex(t_flag *flags, unsigned long data)
{
	set_1_0_for_hex(flags, data);
	write_before_int(flags);
	write_hex(flags, data);
	if (flags->ba_var == 1 && flags->write_left == 1)
		write_after_int(flags);
	if (data == 0)
	{
		if (flags->hexwbool == 1 && flags->prec_bool == 1
			&& flags->width_bool == 0)
			flags->high += 2;
		else if (flags->width > 0 || flags->prec > 0)
			flags->high = flags->high;
		else if (flags->printed == 1 && flags->hexwbool == 0)
			flags->high = 1;
		else if (flags->printed == 0)
			flags->high = 0;
	}
}
