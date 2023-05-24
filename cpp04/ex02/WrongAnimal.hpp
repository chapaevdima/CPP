#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal& rhs);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	~WrongAnimal();

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif