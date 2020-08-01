/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 21:24:24 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/13 01:40:50 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_zero_heading(int cnt_hash, uintmax_t n, char flag)
{
	if (n)
	{
		if (cnt_hash == 1 && flag == 'x')
			write(1, "0x", 2);
		if (cnt_hash == 1 && flag == 'X')
			write(1, "0X", 2);
	}
}

static uintmax_t	ft_get_num(t_struct *my_temp)
{
	uintmax_t	n;

	if (ft_strcmp(my_temp->arg_flags, "hh") == 0)
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

static t_struct		*ft_mount(uintmax_t n, int pos_left,
				char *str, t_struct *my_temp)
{
	int			n_b;
	int			n_w;

	if ((n_w = ft_strlen(str)) && my_temp->hash == 1 && n &&
			my_temp->zero == 1 && my_temp->f_width)
		n_w += 2;
	else if ((n_w = ft_strlen(str)) && my_temp->hash == 1 && n)
	{
		my_temp->f_width -= 2;
		my_temp->len += 2;
	}
	n_b = (n_w <= my_temp->precision && my_temp->precision > 0) ?
		my_temp->precision : n_w;
	my_temp->len += (n_b <= my_temp->f_width) ? my_temp->f_width : n_b;
	if (!pos_left)
		ft_draw(my_temp->f_width - n_b, 0, ' ', my_temp);
	ft_zero_heading(my_temp->hash, n, my_temp->s_flag);
	ft_draw(my_temp->precision - n_w, 0, '0', my_temp);
	ft_putstr(str);
	if (pos_left)
		ft_draw(my_temp->f_width - n_b, 0, ' ', my_temp);
	return (my_temp);
}

t_struct			*ft_printx(t_struct *my_temp)
{
	char		c;
	int			pos_left;
	uintmax_t	n;
	char		*data;

	pos_left = 0;
	n = ft_get_num(my_temp);
	if (n == 0 && my_temp->precision == 0)
	{
		ft_draw(my_temp->f_width, 1, ' ', my_temp);
		return (my_temp);
	}
	c = 'a';
	if (my_temp->s_flag == 'X')
		c = 'A';
	if (!(data = ft_itoa_base(n, 16, c)))
		exit(-1);
	if (my_temp->minus == 1)
		pos_left = 1;
	if (my_temp->zero == 1 && my_temp->precision == -1 && my_temp->minus == 0)
		my_temp->precision = my_temp->f_width;
	ft_mount(n, pos_left, data, my_temp);
	free(data);
	return (my_temp);
}
