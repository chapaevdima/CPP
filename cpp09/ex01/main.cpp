#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "wrong input" << std::endl;
		return 1;
	}

	std::string str = argv[1];

	rpn(str);

	return 0;
}