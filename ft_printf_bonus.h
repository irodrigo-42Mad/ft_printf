/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:27:02 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 23:30:06 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include "./libft/libft.h"

# define SPEC_MASK "cCsSpbdDiuUoOxXyf%"
# define ARGV_MASK "hjlz"
# define CONV_MODF "-+ #0*"

typedef struct	s_params{
	char		*m_format;
	char		*f_copy;
	va_list		args;

	int			printed_n;
	int			i;
	int			len;

	char		s_flag;
	char		*s_mask;
	char		*str;

	char		arg_flags[2];
	char		*arg_mask;

	int			act_flag;
	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			star;

	int			f_width;
	int			hash;
	long int	precision;
	long int	f_precision;
	int			dot;
}				t_struct;

t_struct		*init(t_struct *values);

int				ft_printf(const char *format, ...);

void			ft_draw(int ln, int rest, char ch, t_struct *temp);
void			ft_print_w(wint_t ch, t_struct *temp);

int				format_check(const char *format, t_struct params,
							va_list element, int pos);
int				ft_parser(t_struct *temp);
int				ft_check(t_struct *temp);

t_struct		*ft_modifiers(t_struct *temp);
t_struct		*ft_check_spec(t_struct *temp);
t_struct		*ft_check_width(t_struct *temp);
t_struct		*ft_check_convert(t_struct *temp);
t_struct		*parse_precision(t_struct *temp);
t_struct		*ft_check_precision(t_struct *temp);
t_struct		*ft_check_args(t_struct *temp);

t_struct		*ft_printc(t_struct *temp);
t_struct		*ft_prints(t_struct *my_temp);
t_struct		*ft_printd(t_struct *my_temp);
t_struct		*ft_printu(t_struct *my_temp);
t_struct		*ft_printx(t_struct *my_temp);
t_struct		*ft_printo(t_struct *my_temp);
t_struct		*ft_printp(t_struct *my_temp);
t_struct		*ft_printsw(t_struct *my_temp);
t_struct		*ft_other_chars(t_struct *temp);
t_struct		*ft_put_percent(t_struct *temp);

char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strndup(const char *s, size_t n);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbrmax_fd(intmax_t n, int fd);
char			*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
void			ft_putnbrumax_fd(uintmax_t n, int fd);
char			*ft_strnew(size_t len);

#endif
