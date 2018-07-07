/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:38:28 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/19 16:38:29 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap Constructor called -> without name" << std::endl;
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

FragTrap::FragTrap(std::string name): name(name){
	std::cout << "FragTrap Constructor called -> with name" << std::endl;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::rangedAttack(std::string const & target) {
	std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at range, causing <" << this->rangedAttackDamage <<"> points of damage !" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target) {
		std::cout << "FR4G-TP <" << this->name << "> attacks <" << target << "> at melee, causing <" << this->meleeAttackDamage <<"> points of damage !" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	std::cout << "takeDamage <FragTrap>" << std::endl;
	if (amount < armorDamageReduction) ;
	else if ((hitPoints + armorDamageReduction) < amount) {
		hitPoints = 0;
		std::cout << name << " is died!!!" << std::endl;
	} else {
		hitPoints = hitPoints + armorDamageReduction - amount;
		std::cout << name << " has " << hitPoints << " hitPoints" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount) {
	if ((maxHitPoints - hitPoints) < amount) {
		std::cout << "FR4G-TP <" << this->name << "> Hit repaired by " << (maxHitPoints - hitPoints) << std::endl;
		hitPoints = maxHitPoints;
	} else {
		std::cout << "FR4G-TP <" << this->name << "> Hit repaired by " << amount << std::endl;
		hitPoints += amount;
	}
	if ((maxEnergyPoints - energyPoints) < amount) {
		std::cout << "FR4G-TP <" << this->name << "> Energy repaired by " << (maxEnergyPoints - energyPoints) << std::endl;
		energyPoints = maxEnergyPoints;
	} else {
		std::cout << "FR4G-TP <" << this->name << "> Energy repaired by " << amount << std::endl;
		energyPoints += amount;
	}
}


//setter
void	FragTrap::setHitPoints(unsigned int val) {
	hitPoints = val;
}

void	FragTrap::setMaxHitPoints(unsigned int val) {
	maxHitPoints = val;
}

void	FragTrap::setEnergyPoints(unsigned int val) {
	energyPoints = val;
}

void	FragTrap::setMaxEnergyPoints(unsigned int val) {
	maxEnergyPoints = val;
}

void	FragTrap::setLevel(unsigned int val) {
	level = val;
}

void	FragTrap::setMeleeAttackDamage(unsigned int val) {
	meleeAttackDamage = val;
}

void	FragTrap::setRangedAttackDamage(unsigned int val) {
	rangedAttackDamage = val;
}

void	FragTrap::setArmorDamageReduction(unsigned int val) {
	armorDamageReduction = val;
}

//getter

unsigned int FragTrap::getHitPoints()const {
	return hitPoints;
}

unsigned int FragTrap::getMaxHitPoints()const {
	return maxHitPoints;
}

unsigned int FragTrap::getEnergyPoints()const {
	return energyPoints;
}

unsigned int FragTrap::getMaxEnergyPoints()const {
	return maxEnergyPoints;
}

unsigned int FragTrap::getLevel()const {
	return level;
}

unsigned int FragTrap::getMeleeAttackDamage()const {
	return meleeAttackDamage;
}

unsigned int FragTrap::getRangedAttackDamage()const {
	return rangedAttackDamage;
}

unsigned int FragTrap::getArmorDamageReduction()const {
	return armorDamageReduction;
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
