# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adegarr <adegarr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 15:12:32 by ade-garr          #+#    #+#              #
#    Updated: 2022/01/04 16:02:38 by adegarr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += srcs/ft_atoi.c
SRCS += srcs/ft_strlen.c
SRCS += srcs/ft_printf.c
SRCS += srcs/ft_printf2.c
SRCS += srcs/ft_printf3.c
SRCS += srcs/ft_printf4.c
SRCS += srcs/ft_printf5.c
SRCS += srcs/ft_printf6.c
SRCS += srcs/ft_printf7.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

INCLUDES = ./includes/

CC		= clang

CFLAGS	+= -Wall
CFLAGS	+= -Wextra
CFLAGS	+= -Werror

HEADER = ${INCLUDES}libft.h

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs $@ $^
			printf "\033[32m$@ is ready ! \n\033[0m"

${OBJS}: %.o: %.c ${HEADER}
			${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
	
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
.SILENT:
