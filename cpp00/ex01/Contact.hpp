#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
    static std::string  names[5];
    int                 index;
    std::string         filed[5];
    
public:
    Contact();
    ~Contact();

    bool set(int index);
    void print();
    bool cmp();
    void print_2();
};

#endif