#include "ScalarConverter.hpp"
#include <limits>
#include <string.h>
#include <climits>

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


// gete_type() --> ischar return _char, isint return _int...


//IS_e_type
bool	ScalarConverter::isChar(const std::string &input)
{
	if (input.length() != 1)
	{
		return (false);
	}
	if (input.at(0) < std::numeric_limits<char>::min())
		return (false);
	return (true);
}

bool ScalarConverter::isDigit(const std::string &input)
{
	if (!(input.empty()))
	{
		if (input.length() <= 1 && input[0] != '0')
			return (false);
		for (size_t i = 0; i < input.length(); i++)
			if (!(isdigit(input[i])))
			{
				if (i == 0 && (input[i] == '+' || input[i] == '-'))
					i++;
				else
					return (false);
			}
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &input)
{
	size_t	len = input.length(); // \0 i guess
	bool	has_dot = false;
	if (len < 4 || input[len - 1] != 'f') //checks f at the end + at least 1.1f
		return (false);
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (input[i] == '.')
		{
			if (has_dot == true)
				return (false);
			else
				has_dot = true;
		}
		else if (!isdigit(input[i]))
		{
			if (input[i] == 'f' && i == len - 1)
				i++;
			else
				return false;
		}

		// else if (i != len - 1 && input[i] != '.' && input[i] != 'f' && !isdigit(input[i]))
		// 	return (false);
	}
	if (has_dot != true)
		return (false);
	return (true);
}

bool	ScalarConverter::isDouble(const std::string &input)
{
	size_t	len = input.length(); // \0 i guess
	bool	has_dot = false;
	if (len < 1)
		return (false);
	for (size_t i = 0; i < len; i++)
	{
		if (i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (input[i] == '.')
		{
			if (has_dot == true)
				return (false);
			else
				has_dot = true;
		}
		else if (i != len && input[i] != '.' && !isdigit(input[i]))
			return (false);
	}
	return (true);
}	

bool	ScalarConverter::isSpecial(const std::string &input)
{
	if (strcmp(input.c_str(), "-inf") == 0)
		return (true);
	else if (strcmp(input.c_str(), "+inf") == 0)
		return (true);
	else if (strcmp(input.c_str(), "nan") == 0)
		return (true);
	return (false);
}

e_type	ScalarConverter::getType(const std::string &input)
{
	if (isChar(input))
		return _char;
	else if (isDigit(input))
		return _digit;
	else if (isFloat(input))
		return _float;
	else if (isDouble(input))
		return _double;
	else if (isSpecial(input))
		return _special;
	return error;
} 

void	ScalarConverter::fromChar(std::string input)
{
	float	float_value = static_cast<float>(input[0]);
	double	double_value = static_cast<double>(input[0]);
	
	std::cout << CHAR << input << std::endl;
	std::cout << INT << static_cast<int>(input[0])<< std::endl;
	std::cout << std::fixed << std::setprecision(2) << FLOAT << float_value << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << DOUBLE << double_value << std::endl;
}

void	ScalarConverter::fromInt(std::string input)
{
	int	int_value = std::atoi(input.c_str());
	std::cout << "here " <<int_value<< std::endl;
	if (!(int_value >= 32 && int_value < 127))
		std::cout << CHAR << "Non Printable" << std::endl;
	else
    	std::cout << CHAR << static_cast<char>(int_value) << std::endl;
	if (int_value > INT_MAX)
	{
		std::cout << "HERE?" << std::endl;
		std::cout << INT << "Non Printable" << std::endl;
	}
	else
		std::cout << INT << int_value << std::endl;
	std::cout << FLOAT << static_cast<float>(int_value) << ".00f" << std::endl; //not sure about adding .00
	std::cout << DOUBLE << static_cast<double>(int_value) << ".00" << std::endl; //not sure about adding .00
}

void	ScalarConverter::fromFloat(std::string input)
{
	int	int_value = std::atol(input.c_str());
	std::cout << "here : " << int_value << std::endl;
	if (!(int_value >= 32 && int_value < 127))
		std::cout << CHAR << "Non Printable" << std::endl;
	else
    	std::cout << CHAR << static_cast<char>(int_value) << std::endl;
	std::cout << INT << int_value << std::endl;
	std::cout << FLOAT << input << std::endl;
	std::cout << DOUBLE << static_cast<double>(int_value) << std::endl; 
}

void	ScalarConverter::fromDouble(std::string input)
{
	int	int_value = std::atoi(input.c_str());

	if (!(int_value >= 32 && int_value < 127))
		std::cout << CHAR << "Non Printable" << std::endl;
	else
    	std::cout << CHAR << static_cast<char>(int_value) << std::endl;
	std::cout << INT << int_value << std::endl;
	std::cout << FLOAT << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << DOUBLE << static_cast<double>(int_value) << std::endl;
}

void	ScalarConverter::fromSpecial(std::string input)
{
	if (strcmp("nan", input.c_str()) == 0)
	{
		std::cout << CHAR << "Not A Number" << RESET << std::endl;
		std::cout << INT << "Not A Number" << RESET << std::endl;
		std::cout << FLOAT << "Not A Number" << RESET << std::endl;
		std::cout << DOUBLE << "Not A Number" << RESET << std::endl;
		return ;
	}
	else
	{
		if (input[0] == '-')
		{
			std::cout << CHAR << "-∞" << RESET << std::endl;
			std::cout << INT << "-∞" << RESET << std::endl;
			std::cout << FLOAT << "-∞.00f" << RESET << std::endl;
			std::cout << DOUBLE << "-∞.00" << RESET << std::endl;
		}
		else if (input[0] == '+')
		{
			std::cout << CHAR << "+∞" << RESET << std::endl;
			std::cout << INT << "+∞" << RESET << std::endl;
			std::cout << FLOAT << "+∞.00f" << RESET << std::endl;
			std::cout << DOUBLE << "+∞.00" << RESET << std::endl;
		}
	}
}	

void	ScalarConverter::convert(std::string& input)
{
	switch (getType(input))
	{
		case (_char):
		{
			std::cout << "is char !" << std::endl;
			fromChar(input);
			break;	
		}
		case (_digit):
		{
			std::cout << "is digit !" << std::endl;
			fromInt(input);
			break;
		}
		case (_float):
		{
			std::cout << "is float ~" << std::endl; 
			fromFloat(input);
			break ;
		}
		case (_double):
		{
			std::cout << "is double ~" << std::endl;
			fromDouble(input);
			break;
		}
		case (_special):
		{
			std::cout << "is special " << std::endl;
			fromSpecial(input);
			break;
		}
		default:
			std::cout << "error ~" << std::endl; break;
	}
}
