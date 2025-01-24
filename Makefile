# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 17:46:46 by adechaji          #+#    #+#              #
#    Updated: 2025/01/24 23:23:01 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
# BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= src/ft_printf_extra_utils.c src/ft_printf_utils.c src/ft_printf.c src/ft_split.c \
			src/ft_splithelpers.c src/ft_memcpy.c src/cleanexits.c src/ft_strncmp.c \
			src/ft_strdup.c src/ft_strjoin.c src/ft_calloc.c src/ft_bzero.c src/ft_old_split.c \
			src/ft_strlen.c src/ft_strchr.c src/execution.c pipex.c
# BONUS_SRCS	= src_bonus/
OBJS		= $(SRCS:.c=.o)
# BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

mee: all clean