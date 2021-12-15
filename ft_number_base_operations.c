/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_base_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:16:20 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/15 15:19:05 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_get_digits_base(long long num, int base_len)
{
	int	digits;

	digits = 1;
	while (num / base_len != 0)
	{
		++digits;
		num /= base_len;
	}
	return (digits);
}

long long	ft_get_highest_digit_base(long long num, int base_len)
{
	int	digits;

	digits = ft_get_digits_base(num, base_len);
	if (num < 0)
		return (-(num / ft_power(base_len, digits - 1)));
	return (num / ft_power(base_len, digits - 1));
}

long long	ft_cut_highest_digit_base(long long num, int base_len)
{
	int	digits;

	digits = ft_get_digits_base(num, base_len);
	return (num % ft_power(base_len, digits - 1));
}

int	ft_get_number_digit_base(long long num, int index,
		unsigned long long base_len)
{
	return (num / ft_power(base_len, index - 1) % base_len);
}
