# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 17:45:26 by alcierra          #+#    #+#              #
#    Updated: 2021/12/14 18:04:17 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a
HEADER	=	ft_printf_dev.h
SRCS	=	ft_printf.c				ft_putchar.c			ft_putstr.c			\
			ft_strlen.c				ft_putnbr.c				ft_dec_to_another.c	\
			ft_number_operations.c	ft_number_base_operations.c					\
			ft_putptr.c				ft_putnbr_base.c

B_SRCS	=	ft_lstmap_bonus.c

OBJS	=	${SRCS:.c=.o}
B_OBJS	=	${B_SRCS:.c=.o}
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

bonus:
		@make OBJS="$(B_OBJS)" all

.PHONY: all clean fclean re	bonus

main: all main.o
		gcc ${FLAGS} main.o ${OBJS} -I. -o mandatory

main_t: all
		gcc ${FLAGS} -D READ_FILEDESCRIPTOR=0 -c main.c -o main.o
		gcc ${FLAGS} main.o ${OBJS} -I. -o mandatory

run: main
		./mandatory

run_t: main_t
		./mandatory

push_my: fclean
		git push my master
		git push my test

norminette:
		norminette -R CheckForbiddenSourceHeader ${SRCS}