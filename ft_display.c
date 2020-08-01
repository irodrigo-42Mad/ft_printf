/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:04:40 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/12 12:03:19 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_draw(int ln, int rest, char ch, t_struct *temp)
{
	char	*draft;

	if (ln > 0)
	{
		if (rest != 0)
			temp->len += ln;
		if (!(draft = ft_strnew(ln)))
			exit(-1);
		ft_memset(draft, ch, ln);
		write(1, draft, ln);
		free(draft);
	}
}

t_struct	*ft_other_chars(t_struct *temp)
{
	if (temp->f_copy[temp->i] == '%')
	{
		ft_put_percent(temp);
		return (temp);
	}
	if (temp->zero == 1 && temp->precision <= 0 && !(temp->act_flag == 0))
	{
		temp->precision = temp->f_width;
		temp->f_width = 0;
	}
	if (temp->minus != 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	if (temp->zero == 1)
		ft_draw(temp->f_width - 1, 1, '0', temp);
	write(1, &temp->f_copy[temp->i], 1);
	if (temp->minus == 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	temp->len++;
	return (temp);
}

t_struct	*ft_put_percent(t_struct *temp)
{
	if (temp->zero == 1 && temp->precision <= 0 && temp->minus == 0)
	{
		temp->precision = temp->f_width;
		temp->f_width = 0;
	}
	if (temp->minus != 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	if (temp->zero == 1)
		ft_draw(temp->precision - 1, 1, '0', temp);
	write(1, "%", 1);
	if (temp->minus == 1)
		ft_draw(temp->f_width - 1, 1, ' ', temp);
	temp->len++;
	return (temp);
}
