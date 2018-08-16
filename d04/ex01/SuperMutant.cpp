/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:20:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:20:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return ;
}

SuperMutant::SuperMutant( SuperMutant const &superMutant )
{
	*this = superMutant;
	return ;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
	return ;
}

void SuperMutant::takeDamage( int dam)
{
	dam -= 3;
	if (dam >= 0)
	{
		int hp = getHP();
		hp  -= dam;
		if (hp < 0)
			hp = 0;
		std::cout << "SuperMutant take damage . You have " << hp << " hp!" << std::endl;
	}
	return ;
}

SuperMutant& SuperMutant::operator=( SuperMutant const &rhs )
{
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());

	return (*this);
}
