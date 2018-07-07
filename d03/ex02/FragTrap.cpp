/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:51:43 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 12:51:44 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap::ClapTrap() {
	std::cout << "FragTrap Constructor called -> without name" << std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap::ClapTrap(name) {
	std::cout << "FragTrap Constructor called -> with name" << std::endl;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (energyPoints >= 25) {
		energyPoints -= 25;
		std::string commandAttack[5];
		commandAttack[0] = target + ", I'm gonna kick your fat ass";
		commandAttack[1] = target + ", you'll be screaming - mom, This rock for you";
		commandAttack[2] = target + ", catch My pendal, I'm attacking you";
		commandAttack[3] = target + ", in the mouth your feet";
		commandAttack[4] = target + ", catch my crazy frog";
		std::cout << commandAttack[std::rand() % 5] << std::endl;
	} else {
		std::cout << "Not enough energy point" << std::endl;
	}
}
