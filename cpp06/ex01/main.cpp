#include "Serializer.hpp"

int main(void)
{
	Data numbers;
	numbers.value1 = 239;
	numbers.value2 = 42;

	Data *ptr = &numbers;

	std::cout << "pointer = " << ptr << std::endl;

	uintptr_t iptr = Serializer::serialize(ptr);
	std::cout << "int pointer: " << iptr << std:: endl;

	ptr = Serializer::deserialize(iptr);
	std::cout << "pointer = " << ptr << " value1 = " << ptr->value1 << " value2 = " << ptr->value2 << std::endl;
}