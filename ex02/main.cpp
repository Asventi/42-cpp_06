
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:32:02 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/31 15:32:02 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "doctest.h"
#include <typeinfo>

#include "D.hpp"

Base	*generate()
{
	std::srand(std::clock());
	int	random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "Instancing A\n";
		return (new A());
	}
	if (random == 1)
	{
		std::cout << "Instancing B\n";
		return (new B());
	}
	std::cout << "Instancing C\n";
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Object is of type: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Object is of type: B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Object is of type: C\n";
	else
		std::cout << "Type not recognized\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Object is of type: A\n";
		return ;
	}
	catch (std::bad_cast &) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Object is of type: B\n";
		return ;
	}
	catch (std::bad_cast &) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Object is of type: C\n";
		return ;
	}
	catch (std::bad_cast &) {}
	std::cout << "Type not recognized\n";
}

TEST_CASE("tests")
{
	Base	*p;
	for (int i = 0; i < 4; i++)
	{
		p = generate();
		identify(p);
		delete p;
		std::cout << "\n";
	}
	std::cout << "\n\n References\n";
	for (int i = 0; i < 4; i++)
	{
		p = generate();
		identify(*p);
		delete p;
		std::cout << "\n";
	}
	std::cout << "\n\n Invalid type\n";
	Base	*d = new D();
	identify(d);
	identify(*d);
	delete d;
}
