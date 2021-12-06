/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_another.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:08:00 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/04 17:30:39 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_dev.h"

int	ft_get_base_digits(unsigned long long num, int base_len)
{
	int	count;

	count = 1;
	while (num / base_len)
	{
		num /= base_len;
		++count;
	}
	return (count);
}

char	*ft_dec_to_another(unsigned long long num, char *base)
{
	int		base_len;
	int		num_digit;
	int		curr_digit;
	char	*result;

	curr_digit = 0;
	base_len = ft_strlen(base);
	num_digit = ft_get_base_digits(num, base_len);
	result = (char *) malloc(sizeof(char) * (num_digit + 1));
	if (!result)
		return (result);
	result[num_digit] = 0;
	while (num)
	{
		result[num_digit - curr_digit - 1] = base[num % base_len];
		num /= base_len;
		++curr_digit;
	}
	return (result);
}
