/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:20:38 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 17:20:39 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(std::string type) {
	_type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name) {
	Zombie* zombie = new Zombie(name, this->_type);
	return zombie;
}

Zombie* ZombieEvent::randomZombie() {
	std::string randName[] = {"Grrr", "Brrr", "Frrr", "Drrr"};
	std::string type[] = {"Low", "Norm", "Hard", "Insane"};
	setZombieType(type[std::rand() % 4]);
	Zombie* newZomb = newZombie(randName[std::rand() % 4]);
	newZomb->announce();
	return newZomb;
}

ZombieEvent::~ZombieEvent() {
}
