# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 15:01:31 by urycherd          #+#    #+#              #
#    Updated: 2022/01/20 14:08:52 by urycherd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS = ft_strlen.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
ft_strlcat.c ft_strlcpy.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memcpy.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c flags_p1.c flags_p2.c ft_printf.c \
ft_unsigned_itoa.c get_next_line.c

SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = gcc

FLAG = -Wall -Wextra -Werror

RM = rm -f

LIBC = ar rcs ${NAME}

OBJS = ${SRCS:.c=.o}

OBJS_B = $(SRCS_B:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	${LIBC} $?

${OBJS}: ${HEADER}

${OBJS_B}: ${HEADER}

.c.o:
	@${CC} ${FLAG} -c $< -o $@

TMPFILE = .tempfile

bonus: ${TMPFILE}

${TMPFILE}: ${OBJS_B}
	${LIBC} $?
	@touch ${TMPFILE}

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@${RM} ${TMPFILE}
	@echo "obj deleted"

fclean: clean
	@${RM} ${NAME}
	@echo "all cleaned"

re: fclean all

.PHONY: all clean fclean bonus re