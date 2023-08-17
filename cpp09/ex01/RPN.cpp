#include "RPN.hpp"

void rpn(const std::string& in_str)
{
	std::stringstream ss;
	ss << in_str;

	std::stack<float> nums;
	std::string str;

	while(ss >> str)
	{
		if (str.size() != 1)
		{
			std::cout << "wrong input" << std::endl;
			return;
		}

		if (str[0] == '+')
		{
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num2 = nums.top();
			nums.pop();
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num1 = nums.top();
			nums.pop();
			nums.push(num1 + num2);
		}

		else if (str[0] == '-')
		{
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num2 = nums.top();
			nums.pop();
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num1 = nums.top();
			nums.pop();
			nums.push(num1 - num2);
		}

		else if (str[0] == '*')
		{
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num2 = nums.top();
			nums.pop();
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num1 = nums.top();
			nums.pop();
			nums.push(num1 * num2);
		}

		else if (str[0] == '/')
		{
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num2 = nums.top();
			nums.pop();
			if (nums.empty())
			{
				std::cout << "wrong input" << std::endl;
				return;
			}
			float num1 = nums.top();
			nums.pop();
			nums.push(num1 / num2);
		}

		else if (isdigit(str[0]))
			nums.push(std::atof(str.c_str()));
		
		else
		{
			std::cout << "wrong input" << std:: endl;
			return;
		}
	}

	if (nums.empty())
	{
		std::cout << "wrong input" << std::endl;
		return;
	}

	float res = nums.top();
	nums.pop();

	if (!nums.empty())
	{
		std::cout << "wrong input" << std::endl;
		return;
	}

	std::cout << res << std::endl;
	return;
}