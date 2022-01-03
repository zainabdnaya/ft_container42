# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 13:43:12 by zdnaya            #+#    #+#              #
#    Updated: 2022/01/03 23:08:32 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=vector


SRC=*.cpp

INC=vector.hpp \


all: $(SRC:.cpp=.o)
	@echo "Compiling..."
	@echo "Compiling..."
	@clang++ -g -std=c++98 -pedantic -Wall -Wextra -Werror $(SRC) -o $(NAME)
	@echo "Compiling... Done"

fclean:
	@echo "Cleaning..."
	@rm -f $(NAME)
	@rm -f *.o
	@rm -rf $(NAME).dSYM
	@echo "Cleaning... Done"

re: fclean all
	@echo "Cleaning..."
	@echo "Running..."
	@echo "Running... Done"
