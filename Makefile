# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:45:26 by alcierra          #+#    #+#              #
#    Updated: 2021/12/15 16:17:49 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a
HEADER	=	ft_printf_dev.h
SRCS	=	ft_printf.c				ft_putchar.c			ft_putstr.c			\
			ft_strlen.c				ft_putnbr.c				ft_dec_to_another.c	\
			ft_number_operations.c	ft_number_base_operations.c					\
			ft_putptr.c				ft_putnbr_base.c

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)
		
$(NAME): ${OBJS} ${HEADER}
		ar rcs $(NAME) $?

clean:
		rm -rf mandatory
		rm -rf main.o
		rm -rf ${OBJS} ${B_OBJS}

fclean: clean
		rm -rf ${NAME}

%.o : %.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
