/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 14:52:32 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/16 14:17:31 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	normal_write(const char *str, t_flag *flags)
{
	ft_putchar_fd(str[flags->index], 1, flags);
	flags->index++;
	flags->counter++;
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	t_flag	*flags;

	flags = NULL;
	flags = create_flag(flags);
	if (!flags)
		return (-1);
	flags->index = 0;
	va_start(args, str);
	while (str[flags->index] != '\0' && flags->error != -1)
	{
		if (str[flags->index] != '%')
			normal_write(str, flags);
		if (str[flags->index] == '%' && str[flags->index + 1] == '%')
		{
			flags->index += 2;
			flags->counter++;
			ft_putchar_fd('%', 1, flags);
		}
		if (str[flags->index] == '%' && str[flags->index + 1] != '%')
			load_the_mother((char*)str, flags, args);
	}
	free(flags);
	va_end(args);
	return (flags->counter);
}
