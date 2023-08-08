#include "iter.hpp"

int main (void)
{
	{
		int array[] = {0, 239, 21, 42};
		iter(array, 4, print);
		std::cout << std::endl;
		iter(array, 4, increment);
		iter(array, 4, print);
		std::cout << std::endl;
	}

	{
		char array[] = {'a', 'b', 'c', 'd'};
		iter(array, 4, print);
		std::cout << std::endl;
		iter(array, 4, increment);
		iter(array, 4, print);
		std::cout << std::endl;
	}

	{
		float array[] = {1.1f, 2.2f, 3.3f, 4.2f};
		iter(array, 4, print);
		std::cout << std::endl;
		iter(array, 4, increment);
		iter(array, 4, print);
		std::cout << std::endl;
	}
}