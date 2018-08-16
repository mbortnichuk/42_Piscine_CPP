/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:59 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:13:00 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon( std::string name ) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	this->name = name;
	return ;
}

Peon::Peon( Peon const &peon ) : Victim(peon)
{
	*this = peon;
	return ;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}

void Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony !" << std::endl;
	return ;
}

std::string Peon::getName() const
{
	return (this->name);
}

std::ostream& operator<<(std::ostream &o, Peon const &rhs)
{
	o << "I am " << rhs.getName() << " and I like otters !" << std::endl;
	return ( o );
}
