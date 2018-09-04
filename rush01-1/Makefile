# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 12:57:06 by mbortnic          #+#    #+#              #
#    Updated: 2018/08/29 12:57:08 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC =  $(patsubst %.cpp,%.o,$(wildcard *.cpp))

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror

CC = clang++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lncurses

%.o: %.cpp
	$(CC) $(CFLAGS) -c  -o $@ $< 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

# NAME = ft_gkrellm

# SRC = main.cpp \
# 		CPUModule.cpp \
# 		TimeModule.cpp \
# 		Interface.class.hpp \
# 		HostnameModule.cpp \
# 		NetworkModule.cpp \
# 		OSInfoModule.cpp \
# 		RAMModule.cpp

# FLG = -Wall -Wextra -Werror 
# OBJ = $(SRC:.cpp=.o)
# CC = clang++
# RM = rm -f

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(FLG) -o $(NAME) $(OBJ) -lncurses

# %.o: %.cpp
# 	$(CC) -c -o $@ $<

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all fclean clean all
