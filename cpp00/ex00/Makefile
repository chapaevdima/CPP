NAME	=	megaphone
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS	=	megaphone.cpp

OBJ		=	$(patsubst %.cpp, %.o, $(SRCS))

all		: 	$(NAME)

$(NAME)	: 	$(OBJ)
	$(CC) 	$(CFLAGS) $(OBJ) -o $(NAME)	

clean	:
		rm -f $(OBJ)

fclean	:	 clean
		rm -f $(NAME)

re	:	fclean all
