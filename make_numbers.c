/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_numbers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:13 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/19 14:58:25 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	make_i(t_flag *flags, va_list args)
{
	int	data;

	data = va_arg(args, int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_int(flags, data);
}

void	make_d(t_flag *flags, va_list args)
{
	int	data;

	data = va_arg(args, int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_int(flags, data);
}

void	make_u(t_flag *flags, va_list args)
{
	unsigned int	data;

	data = va_arg(args, unsigned int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_int(flags, data);
}

void	make_x(t_flag *flags, va_list args)
{
	unsigned int	data;

	data = va_arg(args, unsigned int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}

void	make_xx(t_flag *flags, va_list args)
{
	unsigned int	data;

	data = va_arg(args, unsigned int);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}
