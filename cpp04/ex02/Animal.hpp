#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(std::string type);
	Animal(Animal& rhs);
	Animal& operator=(const Animal& rhs);
	virtual ~Animal();

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif