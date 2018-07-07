# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/22 13:11:44 by mbortnic          #+#    #+#              #
#    Updated: 2018/06/22 13:11:46 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
SRC = main.cpp Actions.cpp Champ.cpp Field.cpp GameCore.cpp SpaceShip.cpp
FLG = -Wall -Wextra -Werror 
OBJ = $(SRC:.cpp=.o)
CC = clang++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLG) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp
	$(CC) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean all
