NAME = identify
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Base.cpp

HEADER = Base.hpp A.hpp B.hpp C.hpp

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