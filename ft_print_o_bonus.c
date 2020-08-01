/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:42:53 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 14:43:13 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void			ft_initial_zero(int hash, uintmax_t n)
{
	if (hash == 1 && n)
		write(1, "0", 1);
}

static uintmax_t	ft_get_num(t_struct *my_temp)
{
	uintmax_t	n;

	if (my_temp->s_flag == 'O')
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

static t_struct		*ft_mount(int lft, uintmax_t n,
		char *str, t_struct *my_temp)
{
	int			not_empty;
	int			n_width;

	n_width = ft_strlen(str);
	if (my_temp->hash == 1 && n)
		n_width++;
	not_empty = n_width;
	if (n_width <= my_temp->precision && my_temp->precision > 0)
		not_empty = my_temp->precision;
	my_temp->len += (not_empty <= my_temp->f_width) ?
					my_temp->f_width : not_empty;
	if (!lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	ft_initial_zero(my_temp->hash, n);
	ft_draw(my_temp->precision - n_width, 0, '0', my_temp);
	ft_putstr(str);
	free(str);
	if (lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	return (my_temp);
}

t_struct			*ft_printo(t_struct *my_temp)
{
	uintmax_t	n;
	int			lft;
	char		*str;

	n = ft_get_num(my_temp);
	lft = 0;
	if (n == 0 && my_temp->precision == 0 && my_temp->hash == 0)
	{
		ft_draw(my_temp->f_width, 1, ' ', my_temp);
		return (my_temp);
	}
	if (!(str = ft_itoa_base(n, 8, 'a')))
		exit(-1);
	if (my_temp->minus == 1)
		lft = 1;
	if (my_temp->zero == 1 && my_temp->precision == -1 && my_temp->minus == 0)
		my_temp->precision = my_temp->f_width;
	ft_mount(lft, n, str, my_temp);
	return (my_temp);
}
