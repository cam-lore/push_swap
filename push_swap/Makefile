# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csenecha <csenecha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 17:46:27 by csenecha          #+#    #+#              #
#    Updated: 2023/07/16 00:30:09 by csenecha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 -c
MAKE_LIB = ar -rcs

SRCS = main.c \
	   error_free.c \
	   ft_split.c \
	   mini_sort.c \
	   set_push_swap.c \
	   push_swap.c \
	   push.c \
	   reverse_r.c \
	   rotate.c \
	   stack_init.c \
	   swap.c \
	   utils.c \
	   find.c


OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

	
clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re