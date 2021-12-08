/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:45:01 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/08 14:52:34 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

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

int	ft_putnbr_base_usign_fd(unsigned long long num, char *base, int fd)
{
	int	c;
	int	res;
	int	base_len;

	base_len = ft_strlen(base);
	c = base[num % base_len];
	if (num / base_len > 0)
	{
		res = ft_putnbr_usign_fd(num / base_len, fd);
		write(fd, &c, 1);
		return (1 + res);
	}
	write(fd, &c, 1);
	return (1);
}