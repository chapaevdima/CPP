#include "Harl.hpp"

int main (void)
{
    std::string str;
    Harl harl;

    while (str.compare("EXIT"))
    {
    	std::cout << "Enter a level: ";
    	std::cin >> str;
		  harl.complain(str);
    }
	return 0;
}