/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:31:51 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 22:32:11 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static uintmax_t	ft_get_num(t_struct *my_temp)
{
	uintmax_t	n;

	n = (unsigned long)(va_arg(my_temp->args, unsigned long int));
	n = (uintmax_t)n;
	return (n);
}

static t_struct		*ft_mount(int lft, char *str, t_struct *my_temp)
{
	int		not_empty;
	int		n_width;

	n_width = ft_strlen(str) + 2;
	not_empty = n_width;
	my_temp->len += (not_empty <= my_temp->f_width)
		? my_temp->f_width : not_empty;
	if (!lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	write(1, "0x", 2);
	ft_draw(my_temp->precision - n_width + 2, 1, '0', my_temp);
	ft_putstr(str);
	if (lft)
		ft_draw(my_temp->f_width - not_empty, 0, ' ', my_temp);
	free(str);
	return (my_temp);
}

t_struct			*ft_printp(t_struct *my_temp)
{
	char		*str;
	uintmax_t	n;
	int			lft;

	lft = 0;
	n = ft_get_num(my_temp);
	if (!(str = ft_itoa_base(n, 16, 'a')))
		exit(-1);
	if (my_temp->minus == 1)
		lft = 1;
	if (my_temp->precision == 0 && n == 0)
		*str = '\0';
	if (my_temp->zero == 1 && my_temp->precision == -1 && !my_temp->minus)
	{
		my_temp->precision = my_temp->f_width - 2;
		my_temp->f_width = 0;
	}
	ft_mount(lft, str, my_temp);
	return (my_temp);
}
