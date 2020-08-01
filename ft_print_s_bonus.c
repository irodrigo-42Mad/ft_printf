/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:33:12 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 22:33:35 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_struct			*ft_prints(t_struct *my_temp)
{
	int		ln;
	int		i;

	i = 0;
	my_temp->str = va_arg(my_temp->args, char *);
	if (my_temp->precision > -1 && my_temp->str)
		my_temp->str = ft_strndup(my_temp->str, my_temp->precision);
	else if (my_temp->precision == -1 && my_temp->str)
		my_temp->str = ft_strdup(my_temp->str);
	else if (my_temp->precision > -1 && !my_temp->str)
		my_temp->str = ft_strndup("(null)", my_temp->precision);
	else if (my_temp->precision == -1 && !my_temp->str)
		my_temp->str = ft_strdup("(null)");
	ln = ft_strlen(my_temp->str);
	my_temp->len += ln;
	if (my_temp->zero == 1 && my_temp->minus != 1)
		ft_draw(my_temp->f_width - ln, 1, '0', my_temp);
	else if (my_temp->minus != 1)
		ft_draw(my_temp->f_width - ln, 1, ' ', my_temp);
	ft_putstr(my_temp->str);
	if (my_temp->minus == 1)
		ft_draw(my_temp->f_width - ln, 1, ' ', my_temp);
	return (my_temp);
}
