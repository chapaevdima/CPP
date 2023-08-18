#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	Span sp(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	{
		int arr[] = {0, 1, 2, 3, 2, 3, 9, 4, 2, 5, 10, 42, 239};
		size_t arr_size = sizeof(arr)/sizeof(arr[0]);
		std::vector<int> myvec (arr, arr + arr_size);
		try
		{
			sp.addRange(myvec);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}

	try
	{
		for (int i = 0; i < 20; i++)
			sp.addNumber(i);		
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		std::cout << "Longest span is: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int> myvec(10000);
		std::srand(time(NULL));
		std::generate(myvec.begin(), myvec.end(), std::rand);

		Span span(myvec.size() + 1);

		span.addRange(myvec);

		std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Span span(20);
		std::vector<int> nums(10);
		span.addRange(nums);
		span.addRange(nums.begin(), nums.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}