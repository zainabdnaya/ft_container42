NAME=test


SRC=main.cpp

INC=rbt.hpp
#iterator_traits.hpp \ reverse_traits.hpp \ stack.hpp


all: $(SRC:.cpp=.o)
	@echo "Compiling..."
	@echo "Compiling..."
	@clang++  -std=c++98  -Wall -Wextra -Werror -pedantic $(SRC) -g -o $(NAME)
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
