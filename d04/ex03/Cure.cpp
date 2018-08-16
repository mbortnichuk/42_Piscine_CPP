/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:50:21 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:50:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure(void):
	AMateria("cure")
{}

Cure::Cure(Cure const &src):
	AMateria("cure")
{
	*this = src;
}

Cure::~Cure(void)
{}

Cure				&Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		AMateria::operator=(rhs);
	return (*this);
}

AMateria			*Cure::clone() const
{
	return ((AMateria *)new Cure(*this));
}

void				Cure::use(ICharacter const &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
