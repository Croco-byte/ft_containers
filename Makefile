# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 15:37:37 by user42            #+#    #+#              #
#    Updated: 2021/05/04 15:28:56 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98
#-fsanitize=address -g3 -fno-omit-frame-pointer

SRCS = main.cpp srcs/Vector/tests.cpp
OBJS = ${SRCS:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			rm -f ./test_results/*

re:			fclean all
