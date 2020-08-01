/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:15:19 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/12 12:22:22 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_draw(int ln, int new_len, char ch, t_struct *temp)
{
	char	*chr;

	if (ln > 0)
	{
		if (new_len)
			temp->len += ln;
		if (!(chr = ft_strnew(ln)))
			return ;
		ft_memset(chr, ch, ln);
		write(1, chr, ln);
		free(chr);
	}
}
