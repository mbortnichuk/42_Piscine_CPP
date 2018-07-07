/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:52:25 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 12:52:26 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap::ClapTrap() {
	std::cout << "ScavTrap Constructor called -> without name" << std::endl;
}

ScavTrap::ScavTrap(std::string name):ClapTrap::ClapTrap(name){
	std::cout << "ScavTrap Constructor called -> with name" << std::endl;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::challengeNewcomer() {
	std::string commandAttack[5];
	commandAttack[0] = "Of course I should clean my windows. But privacy is important too.";
	commandAttack[1] = "Broccoli: Hey, I look like a tree.";
	commandAttack[2] = "Mushroom: Wow, I look just like an umbrella.";
	commandAttack[3] = "Walnut: I look exactly like a brain.";
	commandAttack[4] = "Banana: Man, can we change the topic please?";
	std::cout << commandAttack[std::rand() % 5] << std::endl;
}
