NAME = attack
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEADER = Weapon.hpp HumanA.hpp HumanB.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all