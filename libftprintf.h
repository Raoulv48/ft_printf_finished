/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 15:53:32 by rverscho       #+#    #+#                */
/*   Updated: 2020/01/19 14:55:42 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef int		t_bool;
enum {	false, true	};

typedef struct	s_flag
{
	int			index;
	char		flag;
	char		sign;
	int			width;
	t_bool		width_bool;
	int			prec;
	t_bool		prec_bool;
	char		convr;
	t_bool		printed;
	int			counter;
	t_bool		sp_bool;
	int			high;
	t_bool		bool_sign;
	t_bool		write_left;
	t_bool		bb_var;
	t_bool		ba_var;
	char		*hex;
	t_bool		hex_bool;
	t_bool		hexwbool;
	int			i;
	int			len;
	char		towrite;
	t_bool		fit;
	int			error;
}				t_flag;

t_flag			*create_flag(t_flag *empty);
t_flag			*empty_flag(t_flag *empty);
void			fill_struct_to_write_int(t_flag *flags, int data);
void			write_before_int(t_flag *flags);
void			write_after_int(t_flag *flags);
void			set_1_0_for_int(t_flag *fags, int data);
void			fill_struct_to_write_hex(t_flag *flags, unsigned long data);
int				hex_length(unsigned long a, int base);
int				ft_fillstring(unsigned long data, int base, int i,
					t_flag *flags);
void			ft_toupper(char *str, t_flag *flags);
void			ft_tolower(char *str, t_flag *flags);
void			set_sign(t_flag *flags);
void			fill_struct_to_write_str(t_flag *flags, char *data);
void			set_1_0_for_str(t_flag *flags, char *data);
void			write_before_str(t_flag *flags);
void			before_str(t_flag *flags, char *data);
void			make_no_conversion(t_flag *flags);
void			make_c(t_flag *flags, va_list args);
void			make_s(t_flag *flags, va_list args);
void			make_p(t_flag *flags, va_list args);
void			make_d(t_flag *flags, va_list args);
void			make_i(t_flag *flags, va_list args);
void			make_u(t_flag *flags, va_list args);
void			make_x(t_flag *flags, va_list args);
void			make_xx(t_flag *flags, va_list args);
void			ft_putchar_fd(char c, int fd, t_flag *flags);
void			ft_putnbr_fd(unsigned int nb, int fd, t_flag *flags);
void			ft_putstr_fd(char *s, int fd, t_flag *flags);
int				ft_printf(const char *str, ...);
void			load_the_mother(char *str, t_flag *flags, va_list args);
void			ft_flag_handeler(char *str, t_flag *flags, va_list args);
void			starting_space(t_flag *flags);
int				ft_atoi(const char *str, int start);
char			*ft_itoa_base(unsigned long n, int base);
size_t			ft_intlen(const char *str);
size_t			ft_strlen(const char *str);
int				getintlen(unsigned int n);
int				is_specifier(const char *str, int i);
int				is_flag(const char *str, int i);
int				is_num(const char *str, int i);
int				is_precision(const char *str, int i);
void			set_precision(char *str, t_flag *flags, va_list args);
void			set_width(char *str, t_flag *flags, va_list args);
void			set_flag(char *str, t_flag *flags);
void			set_specifier(char *str, t_flag *flags);
#endif
