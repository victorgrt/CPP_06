#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Constructeur par défaut called." << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copie)
{
	(void) copie;
	std::cout << BLUE << "Constructeur par copie called." << RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "Destructeur called." << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copie)
{
	(void) copie;
	std::cout << YELLOW << "Operateur d\'affectation called." << RESET << std::endl;	return *this;
}

enum type{
	error,
	_char,
};

// static bool	isChar(const std::string &input)
// {
// 	if (input.length() != 1)
// 		return (false);
// 	if (input.at(0) < std::numeric_limits<char>::min())
// 		return (false);
// 	return (true);
// }

// getType() --> ischar return _char, isint return _int...
// static type	getType(const std::string &input)
// {
// 	if (isChar(input))
// 		return _char;
// 	return error;
// } 

void	ScalarConverter::convert(std::string& input)
{
	(void) input;
	//char donc care about non printables
	// switch (getType(input))
	// {
	// 	case (_char):
			
	// }

	//int

	//float

	//double
}
