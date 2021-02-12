# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 15:12:32 by ade-garr          #+#    #+#              #
#    Updated: 2020/01/27 17:26:28 by ade-garr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS += ft_atoi.c
SRCS += ft_strlen.c
SRCS += ft_printf.c
SRCS += ft_printf2.c
SRCS += ft_printf3.c
SRCS += ft_printf4.c
SRCS += ft_printf5.c
SRCS += ft_printf6.c
SRCS += ft_printf7.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

INCLUDES = ./

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
