#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, unsigned int size, void (*fun) (T& ))
{
	for (unsigned int i = 0; i < size; i++)
		fun(array[i]);	
}

template<typename T, typename P>
void iter(T *array, unsigned int size, void (*fun) (P& ))
{
	for (unsigned int i = 0; i < size; i++)
		fun(array[i]);	
}

template<typename T>
void print(T& obj)
{
	std::cout << obj << std::endl;
}

template<typename T>
void increment(T& obj)
{
	obj = obj + 1;
}

#endif