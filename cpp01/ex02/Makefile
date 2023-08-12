NAME = program
GCC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(CXXFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

