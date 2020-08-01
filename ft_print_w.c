/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:41:43 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/12 18:47:18 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_ch(wint_t ch, int ln)
{
	unsigned char my_char[ln];

	if (ln == 2)
	{
		my_char[0] = (ch >> (6 * (ln - 1))) + 192;
	}
	else if (ln == 3)
	{
		my_char[0] = (ch >> (6 * (ln - 1))) + 224;
		my_char[1] = ((ch >> 6) & 63) + 128;
	}
	else if (ln == 4)
	{
		my_char[0] = (ch >> (6 * (ln - 1))) + 240;
		my_char[1] = ((ch >> 12) & 63) + 128;
		my_char[2] = ((ch >> 6) & 63) + 128;
	}
	my_char[ln - 1] = ((ch & 63) + 128);
	write(1, my_char, ln);
}

void		ft_print_w(wint_t ch, t_struct *temp)
{
	if (ch <= 127)
	{
		temp->len++;
		ft_putchar(ch);
	}
	if (ch > 127 && ch <= 2047)
	{
		temp->len += 2;
		ft_put_ch(ch, 2);
	}
	if (ch >= 2048 && ch <= 65535)
	{
		temp->len += 3;
		ft_put_ch(ch, 3);
	}
	if (ch >= 65536 && ch <= 2097151)
	{
		temp->len += 4;
		ft_put_ch(ch, 4);
	}
}
