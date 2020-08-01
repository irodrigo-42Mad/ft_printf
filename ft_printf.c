/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:24:20 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/13 01:37:24 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_prepare(t_struct *temp)
{
	temp->arg_flags[0] = '\0';
	temp->arg_flags[1] = '\0';
	temp->precision = -1;
	temp->f_width = 0;
	temp->plus = 0;
	temp->minus = 0;
	temp->zero = 0;
	temp->space = 0;
	temp->hash = 0;
	temp->star = 0;
	temp->dot = 0;
	return (temp);
}

int			ft_parser(t_struct *temp)
{
	if (ft_strcmp(temp->m_format, "%") == 0)
		return (0);
	while (temp->m_format[temp->i] != '\0')
	{
		if (temp->m_format[temp->i] == '%')
		{
			ft_prepare(temp);
			ft_check(temp);
		}
		else
		{
			write(1, &temp->m_format[temp->i], 1);
			temp->len++;
		}
		(temp->m_format[temp->i] != '\0') && (temp->i++);
	}
	return (temp->len);
}

int			ft_check(t_struct *temp)
{
	temp->i++;
	ft_check_convert(temp);
	ft_check_width(temp);
	ft_check_precision(temp);
	ft_check_args(temp);
	ft_check_spec(temp);
	ft_modifiers(temp);
	return (temp->len);
}

int			ft_printf(const char *format, ...)
{
	t_struct	*temp_load;
	int			ln;

	if (!(temp_load = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	temp_load->m_format = (char *)format;
	temp_load = init(temp_load);
	if (format)
	{
		va_start(temp_load->args, format);
		temp_load->len = ft_parser(temp_load);
		va_end(temp_load->args);
	}
	ln = temp_load->len;
	if (temp_load)
		free(temp_load);
	return (ln);
}
