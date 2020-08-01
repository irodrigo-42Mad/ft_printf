/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 17:04:57 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/13 09:40:16 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_char_len(wchar_t ch)
{
	int			ln;

	if (ch <= 127)
		ln = 1;
	else if (ch >= 127 && ch <= 2047)
		ln = 2;
	else if (ch >= 2048 && ch <= 65535)
		ln = 3;
	else
		ln = 4;
	return (ln);
}

static wchar_t		*ft_wstrndup(wchar_t *str1, size_t n)
{
	size_t		pos;
	wchar_t		*str2;

	pos = 0;
	if (!(str2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (str1[pos] && pos < n)
	{
		str2[pos] = str1[pos];
		pos++;
	}
	str2[pos] = '\0';
	return (str2);
}

static wchar_t		*ft_wstrdup(wchar_t *str)
{
	int			ln;

	ln = 0;
	while (str[ln])
		ln++;
	return (ft_wstrndup(str, ln));
}

static t_struct		*ft_put_null(t_struct *my_temp)
{
	wchar_t		*str;
	int			pos;

	pos = 0;
	str = ft_wstrdup(L"(null)");
	if (my_temp->precision > -1)
		while (str[pos] && my_temp->precision-- > 0)
			ft_print_w(str[pos++], my_temp);
	else
		while (str[pos])
			ft_print_w(str[pos++], my_temp);
	free(str);
	return (my_temp);
}

t_struct			*ft_printsw(t_struct *my_temp)
{
	wchar_t		*str;
	int			pos;
	int			j;
	int			ln;

	pos = 0;
	ln = 0;
	if (!(str = (wchar_t *)va_arg(my_temp->args, wchar_t *)))
		return (ft_put_null(my_temp));
	while (str[pos] && !(j = 0))
	{
		if (my_temp->precision > -1 &&
			(ln + ft_char_len(str[pos])) > my_temp->precision)
			break ;
		ln += ft_char_len(str[pos++]);
	}
	if (my_temp->zero == 1 && my_temp->minus == 0)
		ft_draw(my_temp->f_width - ln, 1, '0', my_temp);
	else if (my_temp->minus == 0)
		ft_draw(my_temp->f_width - ln, 1, ' ', my_temp);
	while (j < pos)
		ft_print_w(str[j++], my_temp);
	if (my_temp->minus == 1)
		ft_draw(my_temp->f_width - ln, 1, ' ', my_temp);
	return (my_temp);
}
