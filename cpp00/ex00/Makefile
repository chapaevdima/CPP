NAME	=	megaphone
CC		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	megaphone.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all		: 	$(NAME)

$(NAME)	: 	$(OBJ)
	$(CC) 	$(CXXFLAGS) $(OBJ) -o $(NAME)	

clean	:
		rm -f $(OBJ)

fclean	:	 clean
		rm -f $(NAME)

re	:	fclean all
