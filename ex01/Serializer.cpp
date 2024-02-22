#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

Serializer::Serializer(const Serializer& copie)
{
	(void) copie;
	std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

Serializer::~Serializer()
{
	std::cout << RED << "Destructeur called." << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& copie)
{
	(void) copie;
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}