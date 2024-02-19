#include "ScalarConverter.hpp"
#include <limits>

int main()
{
	ScalarConverter test;
	std::cout << std::boolalpha;
	std::cout << "______________________" << std::endl;
	std::cout << MAGENTA << "CHAR" << RESET << std::endl;
	std::cout << test.isChar("b") << std::endl;
	std::cout << test.isChar("qdoqdo") << std::endl;
	std::cout << MAGENTA << "INT" << RESET << std::endl;
	std::cout << test.isDigit("42") << std::endl;
	std::cout << test.isDigit("+42") << std::endl;
	std::cout << test.isDigit("-42") << std::endl;
	std::cout << test.isDigit("-42-") << std::endl;
	std::cout << test.isDigit("-") << std::endl;
	std::cout << test.isDigit("0") << std::endl;
	std::cout << MAGENTA << "FLOAT" << RESET << std::endl;
	std::cout << test.isFloat("0.0f") << std::endl;
	std::cout << test.isFloat("0.0") << std::endl;
	std::cout << test.isFloat("0...0f") << std::endl;
	std::cout << test.isFloat("000000f") << std::endl;
	std::cout << test.isFloat("42.42f") << std::endl;
	std::cout << test.isFloat("-42.42f") << std::endl;
	std::cout << test.isFloat("+42.42f") << std::endl;
	std::cout << MAGENTA << "DOUBLE" << RESET << std::endl;
	std::cout << test.isDouble("42") << std::endl;
	std::cout << test.isDouble("42") << std::endl;
	std::cout << test.isDouble("42.00") << std::endl;
	std::cout << test.isDouble("42.00f") << std::endl;
	std::cout << test.isDouble("+42.0") << std::endl;
	std::cout << GREEN << "______________________" << RESET << std::endl;
	std::string digit = "42";
	test.convert(digit);
	std::string floater = "42.42f"; 
	test.convert(floater);
	std::string doubler = "42.5";
	test.convert(doubler);
	std::string chara = "c";
	test.convert(chara);
	std::string not_float = "42.42ff";
	test.convert(not_float);
	std::string not_double = "+a42.2f";
	test.convert(not_double);
	std::string not_char = "aijdaidj";
	test.convert(not_char);
	std::cout << GREEN << "______________________" << RESET << std::endl;
	std::string l = "l";
	test.convert(l);
	std::string p = "42";
	test.convert(p);
	std::string f = "75.25f";
	test.convert(f);
	std::string m = "126.005";
	test.convert(m);


	return 0;
}
