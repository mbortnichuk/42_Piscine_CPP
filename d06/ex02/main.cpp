/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:46:43 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 12:46:45 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base 
{
public:
	virtual ~Base() {}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};


Base * generate()
{
	int i = std::rand() % 3;
	if (i == 0)
		return  new A;
	else if (i == 1)
		return  new B;
	else if (i == 2)
		return  new C;

	return new A;
}

void identify_from_pointer( Base * p )
{
	A * a;
	B * b;
	C * c;

	if ((a = dynamic_cast<A *>(p)))
		std::cout << "This is class A" << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "This is class B" << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "This is class C" << std::endl;

}

void	identify_from_reference(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception)
	{

	}
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception)
	{

	}
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception)
	{

	}
}

int		main()
{
	srand(time(0));

	Base * ptr;
	ptr = generate();
	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	delete ptr;
	return 0;
}
