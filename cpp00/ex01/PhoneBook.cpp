#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
    this->max = 8;
    this->current = 0;    
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add()
{
    if(this->current == this->max)
        this->current = 0;
    if (!this->contacts[this->current].set(this->current))
    {
        std::cout << "[ERROR] contact isn't added" << std::endl;
        return;
    }
    this->current++;
}

void PhoneBook::search()
{
	std::string str;
	std::stringstream ss;
	int index;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < this->max; i++)
    {
        if(this->contacts[i].cmp())
            this->contacts[i].print();
    }
    std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "choose index: " << std::endl;
    if (!std::getline(std::cin, str))
        return;
    for (int i = 0; i < str.length(); i++)
    {
        if(!isdigit(str[i]))
        {
            std::cout << "[ERROR] wrong index" << std::endl;
            return;
        }
    }
    ss<<str;
    ss>>index;
    if (index < 0 || index >= 8)
        std::cout << "[ERROR] wrong index" << std::endl;
    else
        this->contacts[index].print_2();
}