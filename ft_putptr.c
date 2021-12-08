/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:26:24 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/08 15:35:23 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_putptr_lower_fd(unsigned long long num, int fd)
{
	int	res;

	res = write(fd, "0x", 2);
	return (res + ft_putnbr_base_usign_fd(num, "0123456789abcdef", fd));
}

int	ft_putptr_upper_fd(unsigned long long num, int fd)
{
	int	res;

	res = write(fd, "0x", 2);
	return (res + ft_putnbr_base_usign_fd(num, "0123456789ABCDEF", fd));
}

int	ft_putptr_upper(unsigned long long num, int fd)
{
	return (ft_putptr_upper_fd(num, fd));
}

int	ft_putptr_lower(unsigned long long num, int fd)
{
	return (ft_putptr_lower_fd(num, fd));
}