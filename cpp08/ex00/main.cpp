#include "easyfind.hpp"

int main(void)
{
	int arr[] = {0, 1, 2, 3, 2, 3, 9, 4, 2, 5, 10, 42, 239};
	size_t arr_size = sizeof(arr)/sizeof(arr[0]);

	std::vector<int> myvector(arr, arr + arr_size);
	std::list<int> mylist(arr, arr + arr_size);
	std::deque<int> mydeque(arr, arr + arr_size);

	std::vector<int>::iterator v_it = easyfind(myvector, 2);
	std::list<int>::iterator l_it = easyfind(mylist, 3410);
	std::deque<int>::iterator d_it = easyfind(mydeque, 239);

	if (v_it != myvector.end())
		std::cout << "found number: " << *v_it << std::endl;
	else
		std::cout << "number not found" << std::endl;

	if (l_it != mylist.end())
		std::cout << "found number: " << *l_it << std::endl;
	else
		std::cout << "number not found" << std::endl;

	if (d_it != mydeque.end())
		std::cout << "found number: " << *d_it << std::endl;
	else
		std::cout << "number not found" << std::endl;
	return 0;
}
