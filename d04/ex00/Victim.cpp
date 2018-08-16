/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:46 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:12:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim( std::string name )
{
	this->name = name;
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
	return ;
}

Victim::Victim( Victim const &victim )
{
	*this = victim;
	return ;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason !" << std::endl;
	return ;
}

void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
	return ;
}

std::string Victim::getName() const
{
	return (this->name);
}

std::ostream& operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I am " << rhs.getName() << " and I like otters !" << std::endl;
	return ( o );
}
