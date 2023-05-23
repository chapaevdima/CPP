NAME = myphonebook
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp

HEADER = PhoneBook.hpp Contact.hpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

