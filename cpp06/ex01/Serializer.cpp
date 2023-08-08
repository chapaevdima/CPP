#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer& Serializer::operator=(const Serializer& rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Serializer::Serializer(const Serializer& src)
{
	*this = src;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}