NAME = bureaucrat
GCC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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