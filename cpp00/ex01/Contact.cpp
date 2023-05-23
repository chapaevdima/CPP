#include "Contact.hpp"

std::string Contact::names[5] = {"First name", "Last name", "Nickname", "Phone number", "Dark secret"};

Contact::Contact() 
{
    for (int i = 0; i < 5; i++)
    {
        this->filed[i] = std::string();
    }
    
}

Contact::~Contact()
{

}

bool Contact::set(int index)
{
    this->index=index;
    for (int i = 0; i < 5; i++)
    {
        std::cout << this->names[i] << ": ";
        if (!getline(std::cin, this->filed[i]))
            return(false);
    }
    for (int i = 0; i < 5; i++)
    {
        if(this->filed[i].length() == 0)
        {
            for (int j = 0; j < 5; j++)
                this->filed[j] = std::string();
            return (false);
        }
    }
    return (true);
}

void Contact::print()
{
    std::cout << "|" << std::setw(10) << this->index << "|";
    for (int i = 0; i < 3; i++)
    {
        if(this->filed[i].length() > 10)
            std::cout << "" << this->filed[i].substr(0,9) << ".|";
        else
            std::cout << std::setw(10) << this->filed[i] << "|";
    }
    std::cout << std::endl;
}

void Contact::print_2()
{
    if (this->filed[0].length() == 0)
    {
        std::cout<<"[ERROR] wrong index"<<std::endl;
        return ;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout <<this->names[i] << " : " << this->filed[i] << std::endl;
    }
}

bool Contact::cmp()
{
    if(this->filed[0].length() > 0)
        return true;
    return false;
}
