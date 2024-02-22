#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};
Base	*generate(void);
class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif