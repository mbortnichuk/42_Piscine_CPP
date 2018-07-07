/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 22:13:36 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/19 22:13:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Constructor called -> without name" << std::endl;
	this->name = "";
	this->hitPoints = 0;
	this->maxHitPoints = 0;
	this->energyPoints = 0;
	this->maxEnergyPoints = 0;
	this->level = 0;
	this->meleeAttackDamage = 0;
	this->rangedAttackDamage = 0;
	this->armorDamageReduction = 0;
}

ScavTrap::ScavTrap(std::string name): name(name){
	std::cout << "ScavTrap Constructor called -> with name" << std::endl;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target) {
	std::cout << "<ScavTrap> <" << this->name << "> attacks <" << target << "> at range, causing <" << this->rangedAttackDamage <<"> points of damage !" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target) {
		std::cout << "<ScavTrap> <" << this->name << "> attacks <" << target << "> at melee, causing <" << this->meleeAttackDamage <<"> points of damage !" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "takeDamage <ScavTrap>" << std::endl;
	if (amount < armorDamageReduction) ;
	else if ((hitPoints + armorDamageReduction) < amount) {
		hitPoints = 0;
		std::cout << name << " is died!!!" << std::endl;
	} else {
		hitPoints = hitPoints + armorDamageReduction - amount;
		std::cout << name << " has " << hitPoints << " hitPoints" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if ((maxHitPoints - hitPoints) < amount) {
		std::cout << "<ScavTrap> <" << this->name << "> Hit repaired by " << (maxHitPoints - hitPoints) << std::endl;
		hitPoints = maxHitPoints;
	} else {
		std::cout << "<ScavTrap> <" << this->name << "> Hit repaired by " << amount << std::endl;
		hitPoints += amount;
	}
	if ((maxEnergyPoints - energyPoints) < amount) {
		std::cout << "<ScavTrap> <" << this->name << "> Energy repaired by " << (maxEnergyPoints - energyPoints) << std::endl;
		energyPoints = maxEnergyPoints;
	} else {
		std::cout << "<ScavTrap> <" << this->name << "> Energy repaired by " << amount << std::endl;
		energyPoints += amount;
	}
}


//setter
void	ScavTrap::setHitPoints(unsigned int val) {
	hitPoints = val;
}

void	ScavTrap::setMaxHitPoints(unsigned int val) {
	maxHitPoints = val;
}

void	ScavTrap::setEnergyPoints(unsigned int val) {
	energyPoints = val;
}

void	ScavTrap::setMaxEnergyPoints(unsigned int val) {
	maxEnergyPoints = val;
}

void	ScavTrap::setLevel(unsigned int val) {
	level = val;
}

void	ScavTrap::setMeleeAttackDamage(unsigned int val) {
	meleeAttackDamage = val;
}

void	ScavTrap::setRangedAttackDamage(unsigned int val) {
	rangedAttackDamage = val;
}

void	ScavTrap::setArmorDamageReduction(unsigned int val) {
	armorDamageReduction = val;
}

//getter

unsigned int ScavTrap::getHitPoints()const {
	return hitPoints;
}

unsigned int ScavTrap::getMaxHitPoints()const {
	return maxHitPoints;
}

unsigned int ScavTrap::getEnergyPoints()const {
	return energyPoints;
}

unsigned int ScavTrap::getMaxEnergyPoints()const {
	return maxEnergyPoints;
}

unsigned int ScavTrap::getLevel()const {
	return level;
}

unsigned int ScavTrap::getMeleeAttackDamage()const {
	return meleeAttackDamage;
}

unsigned int ScavTrap::getRangedAttackDamage()const {
	return rangedAttackDamage;
}

unsigned int ScavTrap::getArmorDamageReduction()const {
	return armorDamageReduction;
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

