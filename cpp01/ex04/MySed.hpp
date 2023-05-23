#ifndef MY_SED_HPP
# define MY_SED_HPP

#include <iostream>
#include <fstream>

class MySed
{
private:
    std::string inFile, outFile;
public:
    MySed(std::string filename);
    ~MySed();
    void replace(std::string s1, std::string s2);
};

#endif