#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string str;
    bool a = true;

    while (a)
    {
        if(!std::getline(std::cin, str))
            return 1;
        if(str == "ADD")
            phonebook.add();
        else if (str == "SEARCH")
            phonebook.search();
        else if (str == "EXIT")
            a = false;
        else
            std::cout << "wrong comand" << std::endl;
    }
    return 0;
}