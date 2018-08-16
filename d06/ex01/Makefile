# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 12:37:34 by mbortnic          #+#    #+#              #
#    Updated: 2018/08/16 12:37:36 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
FLG = -Wall -Wextra -Werror
CC = clang++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLG)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean all clean
