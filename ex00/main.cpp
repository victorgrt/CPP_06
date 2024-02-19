#include "ScalarConverter.hpp"
#include <limits>


static bool	isChar(const std::string &input)
{
	if (input.length() != 1)
		return (false);
	if (input.at(0) < std::numeric_limits<char>::min())
		return (false);
	return (true);
}

static bool isDigit(const std::string &input)
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

static bool	isFloat(const std::string &input)
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
		else if (i != len && input[i] != '.' && input[i] != 'f' && !isdigit(input[i]))
			return (false);
	}
	if (has_dot != true)
		return (false);
	return (true);
}

static bool	isDouble(const std::string &input)
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

int main()
{
	ScalarConverter test;
	std::cout << std::boolalpha;
	std::cout << MAGENTA << "CHAR" << RESET << std::endl;
	std::cout << isChar("b") << std::endl;
	std::cout << isChar("qdoqdo") << std::endl;
	std::cout << MAGENTA << "INT" << RESET << std::endl;
	std::cout << isDigit("42") << std::endl;
	std::cout << isDigit("+42") << std::endl;
	std::cout << isDigit("-42") << std::endl;
	std::cout << isDigit("-42-") << std::endl;
	std::cout << isDigit("-") << std::endl;
	std::cout << isDigit("0") << std::endl;
	std::cout << MAGENTA << "FLOAT" << RESET << std::endl;
	std::cout << isFloat("0.0f") << std::endl;
	std::cout << isFloat("0.0") << std::endl;
	std::cout << isFloat("0...0f") << std::endl;
	std::cout << isFloat("000000f") << std::endl;
	std::cout << isFloat("42.42f") << std::endl;
	std::cout << isFloat("-42.42f") << std::endl;
	std::cout << isFloat("+42.42f") << std::endl;
	std::cout << MAGENTA << "DOUBLE" << RESET << std::endl;
	std::cout << isDouble("42") << std::endl;
	std::cout << isDouble("42") << std::endl;
	std::cout << isDouble("42.00") << std::endl;
	std::cout << isDouble("42.00f") << std::endl;
	std::cout << isDouble("+42.0") << std::endl;
	return 0;
}
