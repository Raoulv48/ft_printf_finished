/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 12:33:49 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/13 16:31:21 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd, t_flag *flags)
{
	flags->error = write(fd, &c, 1);
}

void	ft_putnbr_fd(unsigned int nb, int fd, t_flag *flags)
{
	unsigned int	nbr;

	if (nb < 0)
		nbr = (unsigned int)(nb * -1);
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, flags);
	ft_putchar_fd((char)(nbr % 10 + 48), fd, flags);
}

void	ft_putstr_fd(char *s, int fd, t_flag *flags)
{
	int		i;
	char	c;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0' && flags->error != -1)
		{
			c = s[i];
			flags->error = write(fd, &c, 1);
			i++;
		}
	}
}

int		ft_atoi(const char *str, int start)
{
	long	result;

	result = 0;
	while (str[start] >= '0' && str[start] <= '9')
	{
		if (result >= 922337203685477580)
		{
			result = (result * 10) + (str[start] - '0');
			return ((int)result);
		}
		result = (result * 10) + (str[start] - '0');
		start++;
	}
	return ((int)result);
}
