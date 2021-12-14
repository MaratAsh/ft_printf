/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:14 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/14 17:43:53 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int num, int power)
{
	int	result;

	result = 1;
	while (power)
	{
		result *= num;
		--power;
	}
	return (result);
}

int	ft_get_digits(int num)
{
	int	digits;

	digits = 1;
	while (num / 10 != 0)
	{
		++digits;
		num /= 10;
	}
	return (digits);
}

int	ft_get_highest_digit(long long num)
{
	int	digits;

	digits = ft_get_digits(num);
	if (num < 0)
		return (-(num / ft_power(10, digits - 1)));
	return (num / ft_power(10, digits - 1));
}

int	ft_cut_highest_digit(long long num)
{
	int	digits;

	digits = ft_get_digits(num);
	return (num % ft_power(10, digits - 1));
}

int	ft_get_number_digit(long long num, int index)
{
	return (num / ft_power(10, index - 1) % 10);
}
