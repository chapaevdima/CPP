#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

template<typename T>
class Array
{
private:
	T *array;
	unsigned int len;

	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
public:

	Array();
	Array(unsigned int n);
	Array(const Array<T>& src);
	~Array();

	Array<T>& operator=(const Array<T>& rhs);
	T& operator[](int pos);
	const T& operator[](int pos) const;
	
	unsigned int size() const;
};



template<typename T>
const char * Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Array:exception: Index out of bounds");
}

template<typename T>
Array<T>::Array()
{
		len = 0;
		array = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	len = n;
	array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		array[i] = T();
}

template<typename T>
Array<T>::Array(const Array<T>& src)
{
	array = new T[src.size()];
	len = src.size();
	for (unsigned int i = 0; i < len; i++)
		array[i] = src.array[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this != &rhs)
	{
		delete [] array;
		array = new T[rhs.size()];
		len = rhs.size();
		for (unsigned int i = 0; i < len; i++)
			array[i] = rhs.array[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](int pos) 
{
	if(pos < 0)
		throw OutOfBoundsException();
	if (static_cast<unsigned int>(pos) >= len)
		throw OutOfBoundsException();
	return array[pos];
}

template<typename T>
const T& Array<T>::operator[](int pos) const
{
	if(pos < 0)
		throw OutOfBoundsException();
	if (static_cast<unsigned int>(pos) >= len)
		throw OutOfBoundsException();
	return array[pos];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return len;
}

#endif