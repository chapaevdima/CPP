NAME = program
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

