/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dev.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:54:08 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/08 15:58:01 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEV_H
# define FT_PRINTF_DEV_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_putchar(int c, int *ptr_counter);
int			ft_strlen(char *str);
int			ft_putstr(char *str);

// ft_putnbr.c
int			ft_putnbr(long long num);
int			ft_putnbr_neg_fd(long long num, int fd);
int			ft_putnbr_fd(long long num, int fd);
int			ft_putnbr_usign_fd(unsigned long long num, int fd);

// ft_putnbr_base.c
int			ft_putnbr_base_neg_fd(long long num, char *base, int fd);
int			ft_putnbr_base_fd(long long num, char *base, int fd);
int			ft_putnbr_base_usign_fd(unsigned long long num, char *base, int fd);

// ft_putpointer.c
int			ft_putptr_upper(unsigned long long num, int fd);
int			ft_putptr_lower(unsigned long long num, int fd);
int			ft_putptr_lower_fd(unsigned long long num, int fd);
int			ft_putptr_upper_fd(unsigned long long num, int fd);

// ft_dec_to_another
char		*ft_dec_to_another(unsigned long long num, char *base);
int			ft_get_base_digits(unsigned long long num, int base_len);

// ft_number_operations.c
long long	ft_get_highest_digit(long long num);
long long	ft_cut_highest_digit(long long num);
long long	ft_power(int num, int power);
int			ft_get_digits(long long num);
int			ft_get_number_digit(long long num, int index);

// ft_number_base_operations.c
int			ft_get_digits_base(long long num, int base_len);
long long	ft_get_highest_digit_base(long long num, int base_len);
long long	ft_cut_highest_digit_base(long long num, int base_len);
int			ft_get_number_digit_base(long long num, int index, int base_len);

#endif