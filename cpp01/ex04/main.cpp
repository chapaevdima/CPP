#include "MySed.hpp"

int main (int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return (0);
    }
    MySed sed(argv[1]);
    sed.replace(argv[2], argv[3]);
    return (0);
}