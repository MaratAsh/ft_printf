/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:26:24 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/14 18:40:37 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_dev.h"

int	ft_put_hex_lower_fd(unsigned long num, int fd)
{
	return (ft_putnbr_base_usign_fd(num, "0123456789abcdef", fd));
}

int	ft_put_hex_upper_fd(unsigned long num, int fd)
{
	return (ft_putnbr_base_usign_fd(num, "0123456789ABCDEF", fd));
}

int	ft_putptr_upper(unsigned long num, int fd)
{
	int	res;

	res = write(fd, "0x", 2);
	res += ft_put_hex_upper_fd(num, fd);
	return (res);
}

int	ft_putptr_lower(unsigned long num, int fd)
{
	int	res;

	res = write(fd, "0x", 2);
	res += ft_put_hex_lower_fd(num, fd);
	return (res);
}
