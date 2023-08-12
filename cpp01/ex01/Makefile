NAME = zombie
GCC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

HEADER = Zombie.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CXXFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

