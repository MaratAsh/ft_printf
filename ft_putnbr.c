/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:45:26 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/08 11:34:11 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_putnbr_neg_fd(long long num, int fd)
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

int	ft_putnbr_fd(long long num, int fd)
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

int	ft_putnbr_base_neg_fd(long long num, char *base, int fd)
{
	int	c;
	int	i;
	int	num_digits;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	num_digits = ft_get_digits_base(num, base_len);
	write(fd, "-", 1);
	while (i < num_digits)
	{
		c = base[ft_get_number_digit_base(num, num_digits - i, base_len)];
		write(fd, &c, 1);
		++i;
	}
	return (i + 1);
}

int	ft_putnbr_base_fd(long long num, char *base, int fd)
{
	int	c;
	int	res;
	int	base_len;

	if (num < 0)
		return (ft_putnbr_base_neg_fd(num, base, fd));
	else
	{
		base_len = ft_strlen(base);
		c = base[num % base_len];
		if (num / base_len > 0)
		{
			res = ft_putnbr_fd(num / base_len, fd);
			write(fd, &c, 1);
			return (1 + res);
		}
		write(fd, &c, 1);
		return (1);
	}
	return (0);
}

int	ft_putnbr(long long num)
{
	return (ft_putnbr_fd(num, 1));
}
