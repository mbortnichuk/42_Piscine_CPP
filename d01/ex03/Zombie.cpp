/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:51:00 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 18:51:01 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::string randName[] = {"Grrr", "Brrr", "Frrr", "Drrr"};
	this->_name = randName[std::rand() % 4];
	std::string randType[] = {"Low", "Norm", "Hard", "Insane"};
	this->_type = randType[std::rand() % 4];
}

void	Zombie::announce()const {
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "<" << _name << " (" << _type << ")> is died" << std::endl;
}
