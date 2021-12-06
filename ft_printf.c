/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:41:38 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/06 14:47:58 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_make_rule(char *str, va_list argptr)
{
	int	i;

	i = 0;
	if (*str == 'c')
		ft_putchar('c', &i);
	else if (*str == 's')
		i += ft_putstr(va_arg(argptr, char *));
	else if (*str == 'd')
		i += ft_putnbr(va_arg(argptr, long long));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	int		rule_count;
	va_list	argptr;

	va_start(argptr, str);
	i = 0;
	counter = 0;
	while (i >= 0 && str[i])
	{
		if (str[i] == '%')
		{
			rule_count = ft_make_rule((char *)str + i + 1, argptr);
			counter += rule_count;
			i++;
		}
		else
			ft_putchar((int) str[i], &counter);
		i++;
	}
	va_end(argptr);
	return (counter);
}
