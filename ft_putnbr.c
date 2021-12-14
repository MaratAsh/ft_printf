/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:45:26 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/14 15:44:01 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_putnbr_neg_fd(long num, int fd)
{
	int	c;
	int	i;
	int	num_digits;

	i = 0;
	num_digits = ft_get_digits(num);
	write(fd, "-", 1);
	while (i < num_digits)
	{
		c = '0' - ft_get_number_digit(num, num_digits - i);
		write(fd, &c, 1);
		++i;
	}
	return (i + 1);
}

int	ft_putnbr_fd(long num, int fd)
{
	int	c;
	int	res;

	if (num < 0)
		return (ft_putnbr_neg_fd(num, fd));
	else
	{
		c = '0' + num % 10;
		if (num / 10 > 0)
		{
			res = ft_putnbr_fd(num / 10, fd);
			write(fd, &c, 1);
			return (1 + res);
		}
		write(fd, &c, 1);
		return (1);
	}
	return (0);
}

int	ft_putnbr_usign_fd(unsigned long num, int fd)
{
	int	c;
	int	res;

	c = '0' + num % 10;
	if (num / 10 > 0)
	{
		res = ft_putnbr_usign_fd(num / 10, fd);
		write(fd, &c, 1);
		return (1 + res);
	}
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr(long num)
{
	return (ft_putnbr_fd(num, 1));
}
