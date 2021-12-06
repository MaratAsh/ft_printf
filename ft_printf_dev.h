/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dev.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:54:08 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/06 18:48:15 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEV_H
# define FT_PRINTF_DEV_H

// del
# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_putchar(int c, int *ptr_counter);
int			ft_strlen(char *str);
int			ft_putstr(char *str);
int			ft_putnbr(long long num);
int			ft_putnbr_fd(long long num, int fd);
int			ft_get_base_digits(unsigned long long num, int base_len);
char		*ft_dec_to_another(unsigned long long num, char *base);

// ft_number_operations.c
long long	ft_get_highest_digit(long long num);
long long	ft_cut_highest_digit(long long num);
long long	ft_power(int num, int power);
int			ft_get_digits(long long num);
int			ft_get_number_digit(long long num, int index);

#endif