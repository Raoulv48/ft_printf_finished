/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_flag_handeler.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 13:04:01 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/16 14:03:14 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_handeler(char *str, t_flag *flags, va_list args)
{
	if (is_flag(str, flags->index))
		set_flag(str, flags);
	if (is_num(str, flags->index) || str[flags->index] == '*')
		set_width(str, flags, args);
	if (is_precision(str, flags->index))
		set_precision(str, flags, args);
	if (str[flags->index] != is_specifier(str, flags->index))
		set_specifier(str, flags);
}

void	write_the_mother(t_flag *flags, va_list args)
{
	if (flags->convr == 'c')
		make_c(flags, args);
	else if (flags->convr == 's')
		make_s(flags, args);
	else if (flags->convr == 'p')
		make_p(flags, args);
	else if (flags->convr == 'i')
		make_i(flags, args);
	else if (flags->convr == 'd')
		make_d(flags, args);
	else if (flags->convr == 'u')
		make_u(flags, args);
	else if (flags->convr == 'x')
		make_x(flags, args);
	else if (flags->convr == 'X')
		make_xx(flags, args);
	else if (flags->convr != '\0')
		make_no_conversion(flags);
	else if (flags->convr == '\0')
		flags->error = -1;
}

void	load_the_mother(char *str, t_flag *flags, va_list args)
{
	flags->index++;
	flag_handeler(str, flags, args);
	if (flags->convr != '\0')
	{
		write_the_mother(flags, args);
		flags->counter = flags->counter + flags->high;
	}
	else
		flags->index = ft_strlen(str);
	flags = empty_flag(flags);
}
