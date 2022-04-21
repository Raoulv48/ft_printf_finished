/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:34:16 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/19 16:29:17 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_flag(char *str, t_flag *flags)
{
	while (is_flag(str, flags->index))
	{
		if (str[flags->index] == '+')
			flags->sign = '+';
		if (str[flags->index] == '-')
			flags->flag = '-';
		if (str[flags->index] == ' ')
			flags->sp_bool = 1;
		if (flags->flag != '-')
		{
			if (str[flags->index] == '0')
				flags->flag = '0';
		}
		if (str[flags->index] == '#')
			flags->hex_bool = 1;
		flags->index++;
	}
}

void	set_width(char *str, t_flag *flags, va_list args)
{
	int start;

	if (str[flags->index] == '*')
	{
		start = va_arg(args, int);
		if (start < 0)
		{
			flags->flag = '-';
			start *= -1;
			flags->width = start;
		}
		else
			flags->width = start;
		flags->index++;
	}
	else
	{
		start = flags->index;
		while (is_num(str, flags->index))
			flags->index++;
		flags->width = ft_atoi(str, start);
	}
	flags->width_bool = 1;
}

void	set_precision(char *str, t_flag *flags, va_list args)
{
	int start;

	if (str[flags->index + 1] == '*')
	{
		start = va_arg(args, int);
		if (start == 0)
			flags->prec = 0;
		else
			flags->prec = start;
		flags->index += 2;
	}
	else
	{
		flags->index++;
		start = flags->index;
		while (is_num(str, flags->index))
			flags->index++;
		flags->prec = ft_atoi(str, start);
	}
	if (flags->prec >= 0)
		flags->prec_bool = 1;
}

void	set_specifier(char *str, t_flag *flags)
{
	if (!is_specifier(str, flags->index))
		flags->convr = str[flags->index];
	else if (str[flags->index] == '%')
		flags->convr = str[flags->index];
	else
		flags->convr = '\0';
	flags->index++;
}
