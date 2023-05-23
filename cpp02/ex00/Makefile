NAME = fixed
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Fixed.cpp

HEADER = Fixed.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

