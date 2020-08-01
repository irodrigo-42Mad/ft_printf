/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:38:44 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 23:39:00 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void		ft_putnbrmax_fd(intmax_t n, int fd)
{
	if (n == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void		ft_putnbrumax_fd(uintmax_t n, int fd)
{
	if (n > 9)
		ft_putnbrumax_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

t_struct	*init(t_struct *temp)
{
	temp->len = 0;
	temp->i = 0;
	temp->arg_flags[0] = '\0';
	temp->arg_flags[1] = '\0';
	temp->arg_mask = ARGV_MASK;
	temp->s_mask = SPEC_MASK;
	temp->precision = -1;
	temp->plus = 0;
	temp->minus = 0;
	temp->zero = 0;
	temp->space = 0;
	temp->star = 0;
	temp->f_width = 0;
	temp->f_copy = (char *)temp->m_format;
	return (temp);
}
