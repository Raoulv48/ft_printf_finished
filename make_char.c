/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_char.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 17:41:06 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 16:49:31 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_spacing_char(t_flag *flags, int data)
{
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
	{
		flags->i++;
		ft_putchar_fd(' ', 1, flags);
	}
	if (flags->width_bool == 1 && flags->flag != '-')
	{
		while (flags->width > flags->i + 1)
		{
			ft_putchar_fd(flags->towrite, 1, flags);
			flags->i++;
		}
		ft_putchar_fd(data, 1, flags);
	}
	else if (flags->width_bool == 1 && flags->flag == '-')
	{
		ft_putchar_fd(data, 1, flags);
		while (flags->width > flags->i + 1)
		{
			ft_putchar_fd(flags->towrite, 1, flags);
			flags->i++;
		}
	}
	flags->high = flags->i + 1;
}

void	make_c(t_flag *flags, va_list args)
{
	int		data;

	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	data = va_arg(args, int);
	if (flags->prec_bool != 0 || flags->width_bool != 0)
	{
		add_spacing_char(flags, data);
	}
	else
	{
		ft_putchar_fd(data, 1, flags);
		flags->high++;
	}
}

void	make_s(t_flag *flags, va_list args)
{
	char	*data;
	int		i;

	i = 0;
	data = va_arg(args, char *);
	if (data == NULL)
		data = "(null)";
	if (flags->prec_bool != 0 || flags->width_bool != 0)
		fill_struct_to_write_str(flags, data);
	else
	{
		flags->high = ft_strlen(data);
		ft_putstr_fd(data, 1, flags);
	}
}

void	make_p(t_flag *flags, va_list args)
{
	unsigned long	data;

	flags->hex_bool = 1;
	data = va_arg(args, unsigned long);
	if (data < 0)
	{
		data = data * -1;
		flags->sign = '-';
	}
	fill_struct_to_write_hex(flags, data);
}

void	make_no_conversion(t_flag *flags)
{
	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	if (flags->width != 0)
	{
		if (flags->flag == '-')
			ft_putchar_fd(flags->convr, 1, flags);
		while (flags->i + 1 < flags->width)
		{
			ft_putchar_fd(flags->towrite, 1, flags);
			flags->i++;
		}
		if (flags->flag != '-')
			ft_putchar_fd(flags->convr, 1, flags);
	}
	else
		ft_putchar_fd(flags->convr, 1, flags);
	flags->high = (flags->width >= 1) ? flags->width : 1;
}
