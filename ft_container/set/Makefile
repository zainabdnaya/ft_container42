NAME=set


SRC=*.cpp

INC= set.hpp \
	set_rb.hpp \

all: $(SRC:.cpp=.o)
	@echo "Compiling..."
	@echo "Compiling..."
	@clang++  -std=c++98  -Wall -Wextra -Werror -pedantic  $(SRC) -o $(NAME)
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
