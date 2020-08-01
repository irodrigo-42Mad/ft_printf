/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:05:10 by irodrigo          #+#    #+#             */
/*   Updated: 2020/07/12 12:12:04 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t len)
{
	char *first;

	if (!(first = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_bzero(first, len + 1);
	return (first);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strndup(const char *s, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = ft_calloc((len + 1), sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
