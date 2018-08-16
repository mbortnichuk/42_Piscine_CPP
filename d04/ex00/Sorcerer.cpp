/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:35 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:12:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer( std::string const &name, std::string const &title )
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ", " << this->title << ", " << "is born !" << std::endl;
	return ;
}

Sorcerer::Sorcerer( Sorcerer const &sorcerer )
{
	*this = sorcerer;
	return ;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", " << "is dead. ";
	std::cout << "Consequences will never be the same ! " << std::endl;
	return ;
}

void Sorcerer::polymorph( Victim const & victim) const
{
	victim.getPolymorphed();
	return ;
}

void Sorcerer::polymorph( Peon const & peon) const
{
	peon.getPolymorphed();
	return ;
}

std::string Sorcerer::getName() const
{
	return (this->name);
}

std::string Sorcerer::getTitle() const
{
	return (this->title);
}

std::ostream& operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle();
	o << ", " << "and I like ponies, squirrels" << std::endl;
	return ( o );
}
