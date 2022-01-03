# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:43:12 by zdnaya            #+#    #+#              #
#    Updated: 2022/01/03 21:48:19 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=test


SRC=*.cpp

INC=vector.hpp \


all: $(SRC:.cpp=.o)
	@echo "Compiling..."
	@echo "Compiling..."
	@clang++  -std=c++98 -pedantic -Wall -Wextra -Werror $(SRC) -o $(NAME)
	@echo "Compiling... Done"

fclean:
	@echo "Cleaning..."
	@rm -f test
	@rm -f *.o
	@rm -rf test.dSYM
	@echo "Cleaning... Done"

re: fclean all
	@echo "Cleaning..."
	@echo "Running..."
	@echo "Running... Done"
