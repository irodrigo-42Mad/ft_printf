/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:31:41 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/22 00:30:20 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
