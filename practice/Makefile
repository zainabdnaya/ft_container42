NAME=test


SRC=*.cpp

INC=iterator_traits.hpp \ reverse_traits.hpp \


all: $(SRC:.cpp=.o)
	@echo "Compiling..."
	@echo "Compiling..."
	@clang++ -std=c++98 -Wall -Wextra -Werror $(SRC) -o $(NAME)
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
