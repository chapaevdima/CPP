NAME = iter
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

HEADER = iter.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

%.o: %.cpp $(HEADER)
	$(GCC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all