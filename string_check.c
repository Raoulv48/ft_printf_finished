/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:28:18 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 16:30:30 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_specifier(const char *str, int i)
{
	if (str[i] == 'c')
		return (0);
	if (str[i] == 's')
		return (0);
	if (str[i] == 'p')
		return (0);
	if (str[i] == 'i')
		return (0);
	if (str[i] == 'd')
		return (0);
	if (str[i] == 'u')
		return (0);
	if (str[i] == 'x')
		return (0);
	if (str[i] == 'X')
		return (0);
	return (1);
}

int		is_flag(const char *str, int i)
{
	if (str[i] == '+')
		return (1);
	if (str[i] == '-')
		return (1);
	if (str[i] == ' ')
		return (1);
	if (str[i] == '0')
		return (1);
	if (str[i] == '#')
		return (1);
	return (0);
}

int		is_num(const char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

int		is_precision(const char *str, int i)
{
	if (str[i] == '.')
		return (1);
	return (0);
}

void	starting_space(t_flag *flags)
{
	if (flags->sp_bool == 1 && flags->sign != '-' && flags->sign != '+')
	{
		if (flags->len > flags->prec && flags->flag != '0')
			flags->i++;
		else if (flags->flag == '0' && flags->width > flags->prec)
			flags->i++;
		else if (flags->flag != '-' && flags->width > flags->prec)
			flags->i++;
		ft_putchar_fd(' ', 1, flags);
	}
}
