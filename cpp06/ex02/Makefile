NAME = identify
GCC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Base.cpp

HEADER = Base.hpp A.hpp B.hpp C.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CXXFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all