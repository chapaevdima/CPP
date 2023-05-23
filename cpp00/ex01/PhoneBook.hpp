#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int current;
    int max;
public:
    PhoneBook();
    ~PhoneBook();
    void add(void);
    void search(void);
};

#endif