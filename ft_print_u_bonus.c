/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:35:21 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 22:35:43 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static uintmax_t	ft_get_num(t_struct *my_temp)
{
	uintmax_t	n;

	if (my_temp->s_flag == 'U')
		n = (unsigned long)(va_arg(my_temp->args, unsigned long int));
	else if (ft_strcmp(my_temp->arg_flags, "hh") == 0)
		n = (unsigned char)(va_arg(my_temp->args, unsigned int));
	else if (ft_strcmp(my_temp->arg_flags, "h") == 0)
		n = (unsigned short)(va_arg(my_temp->args, unsigned int));
	else if (ft_strcmp(my_temp->arg_flags, "ll") == 0)
		n = (unsigned long long)(va_arg(my_temp->args, unsigned long long int));
	else if (ft_strcmp(my_temp->arg_flags, "l") == 0)
		n = (unsigned long)(va_arg(my_temp->args, unsigned long int));
	else if (ft_strcmp(my_temp->arg_flags, "j") == 0)
		n = (uintmax_t)(va_arg(my_temp->args, uintmax_t));
	else if (ft_strcmp(my_temp->arg_flags, "z") == 0)
		n = (size_t)(va_arg(my_temp->args, size_t));
	else
		n = (unsigned int)(va_arg(my_temp->args, unsigned int));
	n = (uintmax_t)n;
	return (n);
}

static int			ft_get_digits(uintmax_t num)
{
	int		digits;

	digits = 1;
	while ((num /= 10) > 0)
		digits++;
	return (digits);
}

static t_struct		*ft_mount(uintmax_t n, int lft,
			int n_width, t_struct *my_temp)
{
	int		not_empty;

	not_empty = n_width;
	if (n_width <= my_temp->precision)
		not_empty = my_temp->precision;
	my_temp->len += (not_empty <= my_temp->f_width)
			? my_temp->f_width : not_empty;
	if (!lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	ft_draw(my_temp->precision - n_width, 0, '0', my_temp);
	ft_putnbrumax_fd(n, 1);
	if (lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	return (my_temp);
}

t_struct			*ft_printu(t_struct *my_temp)
{
	uintmax_t	n;
	int			n_width;
	int			lft;

	lft = 0;
	n = ft_get_num(my_temp);
	if (n == 0 && my_temp->precision == 0)
	{
		ft_draw(my_temp->f_width, 1, ' ', my_temp);
		return (my_temp);
	}
	n_width = ft_get_digits(n);
	if (my_temp->minus == 1)
		lft = 1;
	if (my_temp->zero == 1 && my_temp->precision == -1 && my_temp->minus == 0)
		my_temp->precision = my_temp->f_width;
	ft_mount(n, lft, n_width, my_temp);
	return (my_temp);
}
