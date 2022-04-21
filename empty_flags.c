/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   empty_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 16:31:12 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/16 14:11:14 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	*create_flag(t_flag *empty)
{
	empty = malloc(sizeof(t_flag));
	if (empty == NULL)
		return (NULL);
	empty->flag = 0;
	empty->sign = 0;
	empty->width = 0;
	empty->width_bool = 0;
	empty->prec = 0;
	empty->prec_bool = 0;
	empty->convr = 0;
	empty->printed = 0;
	empty->counter = 0;
	empty->sp_bool = 0;
	empty->high = 0;
	empty->bool_sign = 0;
	empty->write_left = 0;
	empty->bb_var = 0;
	empty->ba_var = 0;
	empty->hex = 0;
	empty->hex_bool = 0;
	empty->hexwbool = 0;
	empty->i = 0;
	empty->towrite = 0;
	empty->fit = 0;
	return (empty);
}

t_flag	*empty_flag(t_flag *empty)
{
	empty->flag = 0;
	empty->sign = 0;
	empty->width = 0;
	empty->width_bool = 0;
	empty->prec = 0;
	empty->prec_bool = 0;
	empty->convr = 0;
	empty->printed = 0;
	empty->sp_bool = 0;
	empty->high = 0;
	empty->bool_sign = 0;
	empty->write_left = 0;
	empty->bb_var = 0;
	empty->ba_var = 0;
	empty->hex = 0;
	empty->hex_bool = 0;
	empty->hexwbool = 0;
	empty->i = 0;
	empty->len = 0;
	empty->towrite = 0;
	empty->fit = 0;
	return (empty);
}
