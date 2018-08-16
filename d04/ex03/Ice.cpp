/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:50:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:50:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice(void):
	AMateria("ice")
{}

Ice::Ice(Ice const &src):
	AMateria("ice")
{
	*this = src;
}

Ice::~Ice(void)
{}

Ice					&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

AMateria			*Ice::clone() const
{
	return ((AMateria *)new Ice(*this));
}

void				Ice::use(ICharacter const &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
