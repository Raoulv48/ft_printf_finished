/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:29:36 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 16:30:17 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_intlen(const char *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 9)
		{
			len++;
		}
		i++;
	}
	return (len);
}

int		getintlen(unsigned int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n >= 1 && n <= 9)
		i++;
	return (i);
}
