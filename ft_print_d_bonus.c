/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:42:10 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 14:42:27 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static intmax_t	ft_get_num(t_struct *my_temp)
{
	intmax_t	num;

	if (my_temp->s_flag == 'D')
		num = (long)(va_arg(my_temp->args, long int));
	else if (ft_strcmp(my_temp->arg_flags, "hh") == 0)
		num = (signed char)(va_arg(my_temp->args, int));
	else if (ft_strcmp(my_temp->arg_flags, "h") == 0)
		num = (short)(va_arg(my_temp->args, int));
	else if (ft_strcmp(my_temp->arg_flags, "ll") == 0)
		num = (long long)(va_arg(my_temp->args, long long int));
	else if (ft_strcmp(my_temp->arg_flags, "l") == 0)
		num = (long)(va_arg(my_temp->args, long int));
	else if (ft_strcmp(my_temp->arg_flags, "j") == 0)
		num = (intmax_t)(va_arg(my_temp->args, intmax_t));
	else if (ft_strcmp(my_temp->arg_flags, "z") == 0)
		num = (size_t)(va_arg(my_temp->args, size_t));
	else
		num = (int)(va_arg(my_temp->args, int));
	num = (intmax_t)num;
	return (num);
}

static int		ft_get_digits(intmax_t n)
{
	int digits;

	if (n < 0)
		n *= -1;
	digits = 1;
	while ((n /= 10) > 0)
		digits++;
	return (digits);
}

static char		ft_get_neg_place(int is_neg, t_struct *my_temp)
{
	if (is_neg)
		return ('-');
	if (my_temp->plus == 1)
		return ('+');
	if (my_temp->space == 1)
		return (' ');
	return ('\0');
}

static t_struct	*ft_mount(int al_left, intmax_t n,
			int n_width, t_struct *my_temp)
{
	int			negative_status;
	int			n_fill;
	char		neg_pos_marker;

	negative_status = (n < 0) ? 1 : 0;
	n *= (negative_status && n != (-9223372036854775807 - 1)) ? -1 : 1;
	neg_pos_marker = ft_get_neg_place(negative_status, my_temp);
	n_fill = n_width;
	if (n_width <= my_temp->precision && my_temp->precision >= 0)
		n_fill = my_temp->precision;
	if (neg_pos_marker)
		n_fill++;
	my_temp->len += (n_fill <= my_temp->f_width) ? my_temp->f_width : n_fill;
	if (!al_left)
		ft_draw(my_temp->f_width - n_fill, 0, ' ', my_temp);
	if (neg_pos_marker)
		write(1, &neg_pos_marker, 1);
	ft_draw(my_temp->precision - n_width, 0, '0', my_temp);
	if (n != (-9223372036854775807 - 1))
		ft_putnbrmax_fd(n, 1);
	else if ((my_temp->len += 18) > 0)
		write(1, "9223372036854775808", 19);
	if (al_left)
		ft_draw(my_temp->f_width - n_fill, 0, ' ', my_temp);
	return (my_temp);
}

t_struct		*ft_printd(t_struct *my_temp)
{
	int			char_lft;
	int			n_width;
	intmax_t	n;

	n = ft_get_num(my_temp);
	if (n == 0 && my_temp->precision == 0)
	{
		if (my_temp->plus == 1)
			ft_print_w('+', my_temp);
		if (my_temp->space == 1)
			ft_print_w(' ', my_temp);
		ft_draw(my_temp->f_width, 1, ' ', my_temp);
		return (my_temp);
	}
	n_width = ft_get_digits(n);
	char_lft = (my_temp->minus == 1) ? 1 : 0;
	if (my_temp->zero == 1 && my_temp->precision == -1 && my_temp->minus == 0)
	{
		my_temp->precision = my_temp->f_width;
		if (my_temp->zero != 0 && (n < 0 || my_temp->space == 1 ||
			my_temp->plus == 1 || my_temp->minus == 1))
			my_temp->precision--;
	}
	ft_mount(char_lft, n, n_width, my_temp);
	return (my_temp);
}
