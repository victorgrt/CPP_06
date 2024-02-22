#include "ScalarConverter.hpp"
#include <limits>

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << RED << "Wrong Aguments\nUsage: ./ScalarConverter <x>" << RESET << std::endl, 1);
	std::string str(av[1]);
	try
	{
		ScalarConverter::convert(str);
	}
	catch(ScalarConverter::TypeError &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
