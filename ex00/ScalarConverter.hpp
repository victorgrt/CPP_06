#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iostream>
#include <iomanip> 
#include <cstdlib>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"

enum e_type{
	error,
	_char,
	_digit,
	_float,
	_double
};


class ScalarConverter
{
	private : 
	public : 
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copie);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& copie);

		static bool	isDouble(const std::string &input);
		static bool	isFloat(const std::string &input);
		static bool	isChar(const std::string &input);
		static bool isDigit(const std::string &input);

		static e_type	getType(const std::string &input);

		static void	fromChar(const std::string input);
		static void	fromInt(const std::string input);
		static void	fromFloat(const std::string input);
		static void	fromDouble(const std::string input);

		static void convert(std::string& input);
};

#endif
