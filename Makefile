# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 15:37:37 by user42            #+#    #+#              #
#    Updated: 2021/05/14 16:51:15 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = clang++
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -std=c++98
#

SRCS = main.cpp srcs/Vector/tests.cpp srcs/List/tests.cpp srcs/Stack/tests.cpp srcs/Queue/tests.cpp srcs/Map/tests.cpp

OBJS = ${SRCS:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)
			rm -f ./test_results/*.out

fclean:		clean
			rm -f $(NAME)

re:			fclean all
