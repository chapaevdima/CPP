#include <iostream>

int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr_str = &str;
    std::string &ref_str = str;

    std::cout << "The memory addres of the string variable:    " << &str << std::endl;
    std::cout << "The memory address held by string pointer:   " << ptr_str << std::endl;
    std::cout << "The memory address held by string reference: "<< &ref_str << std::endl;

    std::cout << "The value of the string variable:         " << str << std::endl;
    std::cout << "TThe value pointed to by string pointer:  " << *ptr_str << std::endl;
    std::cout << "The value pointed to by string reference: "<< ref_str << std::endl;
    return 0;
}