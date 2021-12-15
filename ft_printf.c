/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:41:38 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/15 15:31:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_make_rule(char *str, va_list argptr)
{
	int	i;

	i = 0;
	if (*str == 'c')
		ft_putchar(va_arg(argptr, int), &i);
	else if (*str == '%')
		i += write(1, "%%", 1);
	else if (*str == 's')
		i += ft_putstr(va_arg(argptr, char *));
	else if (*str == 'd')
		i += ft_putnbr(va_arg(argptr, int));
	else if (*str == 'i')
		i += ft_putnbr(va_arg(argptr, int));
	else if (*str == 'u')
		i += ft_putnbr(va_arg(argptr, unsigned int));
	else if (*str == 'p')
		i += ft_putptr_lower((unsigned long) va_arg(argptr, void *), 1);
	else if (*str == 'x')
		i += ft_put_hex_lower_fd((unsigned int) va_arg(argptr, int), 1);
	else if (*str == 'X')
		i += ft_put_hex_upper_fd((unsigned int) va_arg(argptr, int), 1);
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
