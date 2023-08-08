#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_Data
{
	int value1;
	int value2;
} Data;

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& src);
	Serializer& operator=(const Serializer& rhs);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif