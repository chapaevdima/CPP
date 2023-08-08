#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array
{
private:
	T *array;
	unsigned int len;

	class OutOfBoundsException: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Array:exception: Index out of bounds");
			}
	};
	
public:
	Array<T>()
	{
		len = 0;
		array = new T[0];
	}

	Array<T>(unsigned int n)
	{
		len = n;
		array = new T[n];
		for (unsigned int i = 0; i < n; i++)
			array[i] = T();
		
	}

	~Array<T>()
	{
		
		delete [] array;
	}

	Array<T>& operator=(const Array<T>& rhs)
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

	Array<T>(const Array<T>& src)
	{
		array = new T[src.size()];
			len = src.size();
			for (unsigned int i = 0; i < len; i++)
				array[i] = src.array[i];
	}

	T& operator[](unsigned int pos) const
	{
		if (pos > len)
			throw OutOfBoundsException();
		return array[pos];
	}
	
	unsigned int size() const
	{
		return len;
	}
};




#endif