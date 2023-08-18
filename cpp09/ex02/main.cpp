#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: not enough arguments" << std::endl;
        return 1;
    }

    std::vector<int> int_vector;
    std::list<int> int_list;

    int num_elem;
    for (int i = 1; i < argc; i++)
    {
		for(int j = 0; argv[i][j] != '\0'; j++)
		{
			if(!(isdigit(argv[i][j]) || (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))))
			{
				std::cout << "Error: non-numeric character" << std::endl;
				return 1;
			}
		}
		if(std::atoi(argv[i]) < 0)
		{
			std::cout << "Error: not a positive number" << std::endl;
			return 1;
		}
        int_vector.push_back(std::atoi(argv[i]));
        int_list.push_back(std::atoi(argv[i]));
		num_elem = i;
    }

    std::cout << "Before: ";
    for (unsigned int i = 0; i < int_vector.size(); i++)
        std::cout << int_vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Before: ";
    std::list<int>::iterator it = int_list.begin();
    for (; it != int_list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t vstart = clock();
	vectorSort(int_vector);
    clock_t vend = clock();
    double vec_time = static_cast<double>(vend - vstart) * 1000 / CLOCKS_PER_SEC;

    clock_t lstart = clock();
    listSort(int_list);
    clock_t lend = clock();
    double list_time = static_cast<double>(lend - lstart) * 1000 / CLOCKS_PER_SEC;

	std::cout << "After:  ";
    for (unsigned int i = 0; i < int_vector.size(); i++)
        std::cout << int_vector[i] << " ";
    std::cout << std::endl;
    
    std::cout << "After:  ";
	it = int_list.begin();
    for (; it != int_list.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << num_elem << " elements with std::vector<int> : " << vec_time << "ms" << std::endl;
	std::cout << "Time to process a range of " << num_elem << " elements with std::list<int> : " << list_time << "ms" << std::endl;
}