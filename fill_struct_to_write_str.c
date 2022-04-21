/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct_to_write_str.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:34:33 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 17:17:59 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	before_str(t_flag *flags, char *data)
{
	set_1_0_for_str(flags, data);
	if (flags->bb_var == 1)
		write_before_str(flags);
}

void	write_str(t_flag *flags, char *data)
{
	int i;

	i = 0;
	while (i < flags->len)
	{
		ft_putchar_fd(data[i], 1, flags);
		i++;
	}
}

void	finish_str_left(t_flag *flags)
{
	if (flags->ba_var == 1 && flags->write_left == 1)
	{
		flags->i = flags->len;
		while (flags->i < flags->high)
		{
			ft_putchar_fd(flags->towrite, 1, flags);
			flags->i++;
		}
	}
}

void	fill_struct_to_write_str(t_flag *flags, char *data)
{
	before_str(flags, data);
	write_str(flags, data);
	finish_str_left(flags);
}
