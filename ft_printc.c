/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:29:42 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/13 11:07:29 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_printc(t_struct *temp)
{
	wint_t c;

	if (ft_strcmp(temp->arg_flags, "l") == 0)
		c = (wint_t)((unsigned long)va_arg(temp->args, unsigned long));
	else if (temp->arg_flags[0] == 'C')
		c = (wint_t)((wchar_t)va_arg(temp->args, wint_t));
	else
		c = (wint_t)((char)va_arg(temp->args, int));
	if (temp->minus != 1 && temp->zero == 1)
		ft_draw(temp->f_width - 1, 1, '0', temp);
	if (temp->minus != 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	ft_print_w(c, temp);
	if (temp->minus == 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	return (temp);
}
