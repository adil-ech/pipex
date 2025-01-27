# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 17:46:46 by adechaji          #+#    #+#              #
#    Updated: 2025/01/27 17:31:53 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= src/ft_printf_extra_utils.c src/ft_printf_utils.c src/ft_printf.c src/ft_split.c \
			src/ft_splithelpers.c src/ft_memcpy.c src/cleanexits.c src/ft_strncmp.c \
			src/ft_strdup.c src/ft_strjoin.c src/ft_calloc.c src/ft_bzero.c src/ft_old_split.c \
			src/ft_strlen.c src/ft_strchr.c src/ft_putstr_fd.c src/execution.c src/pars_pipe.c pipex.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all