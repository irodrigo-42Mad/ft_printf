/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_threatment_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:30:57 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/21 23:31:12 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_struct	*ft_check_precision(t_struct *temp)
{
	while (temp->f_copy[temp->i] == '.' && temp->i++)
		temp->precision = 0;
	while (temp->f_copy[temp->i] == '-')
	{
		temp->i++;
		temp->minus = 1;
	}
	if (temp->f_copy[temp->i] != '*' && temp->precision == 0)
	{
		while (temp->f_copy[temp->i] >= '0' && temp->f_copy[temp->i] <= '9')
		{
			temp->precision *= 10;
			temp->precision += (temp->f_copy[temp->i] - 48);
			temp->i++;
		}
	}
	else if (temp->f_copy[temp->i] == '*' && temp->precision == 0)
	{
		temp->i++;
		temp->star = 1;
		temp->precision = va_arg(temp->args, int);
		if (temp->precision < 0)
			temp->minus = 1;
	}
	return (temp);
}

t_struct	*ft_check_convert(t_struct *temp)
{
	size_t	i;

	i = 0;
	while (CONV_MODF[i] != '\0')
	{
		while (CONV_MODF[i] == temp->f_copy[temp->i])
		{
			while (temp->f_copy[temp->i] == '-' && temp->i++)
				temp->minus = 1;
			while (temp->f_copy[temp->i] == '+' && temp->i++)
				temp->plus = 1;
			while (temp->f_copy[temp->i] == ' ' && temp->i++)
				temp->space = 1;
			while (temp->f_copy[temp->i] == '0' && temp->i++)
				temp->zero = 1;
			while (temp->f_copy[temp->i] == '#' && temp->i++)
				temp->hash = 1;
			while (temp->f_copy[temp->i] == '*' && temp->i++)
				temp->star = 1;
			i = 0;
		}
		i++;
	}
	return (temp);
}

t_struct	*ft_check_width(t_struct *temp)
{
	if (temp->f_copy[temp->i] >= '0' && temp->f_copy[temp->i] <= '9')
	{
		while (temp->f_copy[temp->i] >= '0' && temp->f_copy[temp->i] <= '9')
		{
			temp->f_width *= 10;
			temp->f_width += (temp->f_copy[temp->i] - 48);
			temp->i++;
		}
	}
	else if (temp->star == 1)
	{
		temp->f_width = va_arg(temp->args, int);
		if (temp->f_width < 0)
		{
			temp->minus = 1;
			temp->f_width *= -1;
		}
	}
	return (temp);
}

t_struct	*ft_check_spec(t_struct *temp)
{
	size_t i;

	i = 0;
	while (temp->s_mask[i] != '\0')
	{
		if (temp->s_mask[i] == temp->f_copy[temp->i])
			temp->s_flag = temp->s_mask[i];
		i++;
	}
	return (temp);
}

t_struct	*ft_check_args(t_struct *temp)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (temp->arg_mask[i] != '\0')
	{
		while (temp->arg_mask[i] == temp->f_copy[temp->i])
		{
			temp->arg_flags[j] = temp->f_copy[temp->i];
			temp->arg_flags[j + 1] = '\0';
			temp->i++;
			j++;
		}
		i++;
	}
	return (temp);
}
