/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_1_0_for_str.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:54:40 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 15:58:11 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_1_0_for_str(t_flag *flags, char *data)
{
	flags->len = ft_strlen(data);
	flags->len = (flags->prec < flags->len && flags->prec_bool == 1)
		? flags->prec : flags->len;
	flags->high = (flags->width > flags->len) ? flags->width : flags->len;
	flags->write_left = (flags->flag == '-' || flags->width < flags->len)
		? 1 : 0;
	flags->bb_var = (flags->width > flags->len && flags->write_left == 0)
		? 1 : 0;
	flags->ba_var = (flags->len < flags->high) ? 1 : 0;
	flags->towrite = (flags->flag == '0') ? '0' : ' ';
	flags->fit = (flags->len <= flags->prec) ? 0 : 1;
}

void	write_before_str(t_flag *flags)
{
	int i;

	i = 0;
	while (i + flags->len < flags->width)
	{
		ft_putchar_fd(flags->towrite, 1, flags);
		i++;
	}
}
