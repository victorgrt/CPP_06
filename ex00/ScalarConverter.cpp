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


// gete_type() --> ischar return _char, isint return _int...


//IS_e_type
bool	ScalarConverter::isChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
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
	return error;
} 

void	ScalarConverter::fromChar(std::string input)
{
	float	float_value = static_cast<float>(input[0]);
	double	double_value = static_cast<double>(input[0]);
	
	std::cout << "char : " << input << std::endl;
	std::cout << "int : " << static_cast<int>(input[0])<< std::endl;
	std::cout << std::fixed << std::setprecision(2) << "float : " << float_value << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "double : " << double_value << std::endl;
}

void	ScalarConverter::fromInt(std::string input)
{
	int	int_value = std::atoi(input.c_str());

    std::cout << "char : " << static_cast<char>(int_value) << std::endl;
	std::cout << "int : " << int_value << std::endl;
	std::cout << "float : " << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(int_value) << std::endl;
}

void	ScalarConverter::fromFloat(std::string input)
{
	int	int_value = std::atoi(input.c_str());

	std::cout << "char : " << static_cast<char>(int_value) << std::endl;
	std::cout << "int : " << int_value << std::endl;
	std::cout << "float : " << input << std::endl;
	std::cout << "double : " << static_cast<double>(int_value) << std::endl; 
}

void	ScalarConverter::fromDouble(std::string input)
{
	int	int_value = std::atoi(input.c_str());

	std::cout << "char : " << static_cast<char>(int_value) << std::endl;
	std::cout << "int : " << int_value << std::endl;
	std::cout << "float : " << static_cast<float>(int_value) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(int_value) << std::endl;
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
		default:
			std::cout << "error ~" << std::endl; break;
	}
}
