#include "Array.hpp"
#define SIZE 20

int main(void)
{
	Array<int> intarr(SIZE);
	Array<int> arrint(SIZE * 2);
	Array<float> farr = Array<float>(0);

	for (unsigned int i = 0; i < intarr.size(); i++)
		intarr[i] = i;

	for (unsigned int i = 0; i < arrint.size(); i++)
		arrint[i] = i * 2;

	std::cout << "arrint:";
	for (unsigned int i = 0; i < arrint.size(); i++)
		std::cout << " " << arrint[i]; 

	std::cout << std::endl;
	std::cout << "intarr:";
	for (unsigned int i = 0; i < intarr.size(); i++)
		std::cout << " " << intarr[i];
	

	Array<int> test(intarr);
	intarr = arrint;

	std::cout << std::endl << "intarr:";
	for (unsigned int i = 0; i < intarr.size(); i++)
		std::cout << " " << intarr[i]; 

	std::cout << std::endl;

	try
	{
		std::cout << "valid index " << intarr[intarr.size() / 2] << std::endl;
		std::cout << "invalid index" << intarr[intarr.size() + 1];
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}