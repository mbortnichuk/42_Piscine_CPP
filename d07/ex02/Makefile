# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 14:19:55 by mbortnic          #+#    #+#              #
#    Updated: 2018/06/28 14:19:56 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array
SRC = main.cpp
FLG = -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)
CC = clang++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLG) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean all
