#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "wrong input" << std::endl;
        return 1;
    }

    std::vector<int> int_vector;
    std::list<int> int_list;

    for (int i = 1; i < argc; i++)
    {
        int_vector.push_back(std::atoi(argv[i]));
        int_list.push_back(std::atoi(argv[i]));
    }

    /*std::cout << "Before: ";
    for (unsigned int i = 0; i < int_vector.size(); i++)
        std::cout << int_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Before: ";
    std::list<int>::iterator it = int_list.begin();
    for (; it != int_list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;*/

	vectorSort(int_vector);
	std::cout << "After: ";
    for (unsigned int i = 0; i < int_vector.size(); i++)
        std::cout << int_vector[i] << " ";
    std::cout << std::endl;
}