# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 17:12:54 by tnave             #+#    #+#              #
#    Updated: 2021/12/03 12:52:25 by tigerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRCS = 	srcs/philosopher.c \
		srcs/thread.c \
		srcs/thread_two.c \
		srcs/utils.c \
		srcs/utils_two.c \
		srcs/init.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include/ -pthread 

HEADER = -I ./includes/

OBJ = $(SRCS:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

all: $(NAME)

%.o%.c:
	$(CC) -c $(CFLAGS) -I $(HEADER) $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re