#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

class ScalarConverter
{
	private : 
	public : 
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copie);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& copie);

		static void convert(std::string& input);
};

#endif
