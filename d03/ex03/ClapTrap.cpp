/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:53:59 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 19:54:00 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap Constructor called -> without name" << std::endl;
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

ClapTrap::ClapTrap(std::string name): name(name) {
	std::cout << "ClapTrap Constructor called -> with name" << std::endl;
	hitPoints = 100;
	maxHitPoints = 100;
	level = 1;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::rangedAttack(std::string const & target) {
		std::cout << "ClapTrap <" << this->name << "> attacks <" << target << "> at range, causing <" << this->rangedAttackDamage <<"> points of damage !" << std::endl;
}

void ClapTrap:: meleeAttack(std::string const & target) {
	std::cout << "ClapTrap <" << this->name << "> attacks <" << target << "> at melee, causing <" << this->meleeAttackDamage <<"> points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap takeDamage" << std::endl;
	if (amount < armorDamageReduction) ;
	else if ((hitPoints + armorDamageReduction) < amount) {
		hitPoints = 0;
		std::cout << name << " is died!!!" << std::endl;
	} else {
		hitPoints = hitPoints + armorDamageReduction - amount;
		std::cout << name << " has " << hitPoints << " hitPoints" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if ((maxHitPoints - hitPoints) < amount) {
		std::cout << "ClapTrap <" << this->name << "> Hit repaired by " << (maxHitPoints - hitPoints) << std::endl;
		hitPoints = maxHitPoints;
	} else {
		std::cout << "ClapTrap <" << this->name << "> Hit repaired by " << amount << std::endl;
		hitPoints += amount;
	}
	if ((maxEnergyPoints - energyPoints) < amount) {
		std::cout << "ClapTrap <" << this->name << "> Energy repaired by " << (maxEnergyPoints - energyPoints) << std::endl;
		energyPoints = maxEnergyPoints;
	} else {
		std::cout << "ClapTrap <" << this->name << "> Energy repaired by " << amount << std::endl;
		energyPoints += amount;
	}
}

//setter
void	ClapTrap::setHitPoints(unsigned int val) {
	hitPoints = val;
}

void	ClapTrap::setMaxHitPoints(unsigned int val) {
	maxHitPoints = val;
}

void	ClapTrap::setEnergyPoints(unsigned int val) {
	energyPoints = val;
}

void	ClapTrap::setMaxEnergyPoints(unsigned int val) {
	maxEnergyPoints = val;
}

void	ClapTrap::setLevel(unsigned int val) {
	level = val;
}

void	ClapTrap::setMeleeAttackDamage(unsigned int val) {
	meleeAttackDamage = val;
}

void	ClapTrap::setRangedAttackDamage(unsigned int val) {
	rangedAttackDamage = val;
}

void	ClapTrap::setArmorDamageReduction(unsigned int val) {
	armorDamageReduction = val;
}

//getter

unsigned int ClapTrap::getHitPoints()const {
	return hitPoints;
}

unsigned int ClapTrap::getMaxHitPoints()const {
	return maxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints()const {
	return energyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints()const {
	return maxEnergyPoints;
}

unsigned int ClapTrap::getLevel()const {
	return level;
}

unsigned int ClapTrap::getMeleeAttackDamage()const {
	return meleeAttackDamage;
}

unsigned int ClapTrap::getRangedAttackDamage()const {
	return rangedAttackDamage;
}

unsigned int ClapTrap::getArmorDamageReduction()const {
	return armorDamageReduction;
}


std::string ClapTrap::getName()const {
	return name;
}

