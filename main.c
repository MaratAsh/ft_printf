/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:58:36 by alcierra          #+#    #+#             */
/*   Updated: 2021/12/06 19:26:01 by alcierra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_dev.h"
#include "ft_printf.h"

void	test_header(char *str)
{
	printf("_____________________________________________\n\n");
	printf("%s\n", str);
	printf("_____________________________________________\n");
}

void	test_expected(char *str)
{
	printf("should:\t%s\n", str);
}

void	test_expected_str(char *str)
{
	printf("should:\t%s\n", str);
}

void	test_expected_int(int num)
{
	printf("should:\t%d\n", num);
}

void	test_result_str(char *str)
{
	printf("return:\t%s\n", str);
}

void	test_result_int(int num)
{
	printf("return:\t%d\n", num);
}

void	function_tests()
{
	test_header("ft_get_base_digits(17, 16)");

	test_expected("2");
	test_result_int(ft_get_base_digits(17, 16));

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif
	
	test_header("ft_dec_to_another(123456789, \"0123456789\")");
	test_expected("123456789");
	test_result_str(ft_dec_to_another(123456789, "0123456789"));

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif

	test_header("ft_dec_to_another(123456789, \"0123456789ABCDEF\")");
	test_expected("75BCD15");
	test_result_str(ft_dec_to_another(123456789, "0123456789ABCDEF"));

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif
}

void function_test_printf()
{
	test_header("f(\"%s\", \"012\")");
	test_expected_int(printf("%s\n", "012"));
	test_result_int(ft_printf("%s\n", "012"));

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif

	test_header("f(\"\\n%s\\nnum:\\t%d\\n\", \"String in string\", 5000000000)");
	test_expected_int(
		printf("\n%s\nnum:\t%d\n", "String in string", 50000000)
	);
	test_result_int(
		ft_printf("\n%s\nnum:\t%d\n", "String in string", 50000000)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif
}


int	main(void)
{
	function_test_printf();
	//printf("_____________________________________________\n");
	//ft_printf("%d\n", 54554);
	
	//#ifdef READ_FILEDESCRIPTOR
	//read(READ_FILEDESCRIPTOR, "", 1);
	//#endif
	
	//function_tests();

	test_header("ft_get_number_digit(12345, 1)");
	test_expected_int(
		5
	);
	test_result_int(
		ft_get_number_digit(12345, 1)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif

	test_header("ft_get_highest_digit(-12345)");
	test_expected_int(
		1
	);
	test_result_int(
		ft_get_highest_digit(-12345)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif

	test_header("ft_cut_highest_digit(-12345)");
	test_expected_int(
		-2345
	);
	test_result_int(
		ft_cut_highest_digit(-12345)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif
	
	test_header("ft_putnbr_fd(50000, 1)");
	printf("50000");
	test_expected_int(
		5
	);
	test_result_int(
		ft_putnbr_fd(50000, 1)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif

	test_header("ft_putnbr_fd(-50000, 1)");
	printf("-50000");
	test_expected_int(
		6
	);
	test_result_int(
		ft_putnbr_fd(-50000, 1)
	);

	#ifdef READ_FILEDESCRIPTOR
	read(READ_FILEDESCRIPTOR, "", 1);
	#endif
}
