#include "Base.hpp"
#include <ctime>

Base*	generate(void)
{
	static bool flag = false;

	if (!flag)
	{
		srand(time(NULL)); 
		flag = true;
	}
	int random = rand();
	if (random % 3 == 0)
	{
		std::cout << "Class A created" << std::endl;
		return (new A);
	}
	else if (random % 3 == 1)
	{
		std::cout << "Class B created" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Class C created" << std::endl;
		return (new C);
	}
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &ptr)
{
	try
	{
		A& a = dynamic_cast<A&>(ptr);
		std::cout << "A" << std::endl;
		(void) a;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(ptr);
		std::cout << "B" << std::endl;
		(void) b;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(ptr);
		std::cout << "C" << std::endl;
		(void) c;
		return ;
	}
	catch(const std::exception& e){}
}

int	main(void)
{
    Base*   a = generate();
    
	std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << std::endl;

    delete a;
	return (0);
}