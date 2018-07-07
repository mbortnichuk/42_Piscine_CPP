# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 19:41:13 by mbortnic          #+#    #+#              #
#    Updated: 2018/06/13 19:41:14 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
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
