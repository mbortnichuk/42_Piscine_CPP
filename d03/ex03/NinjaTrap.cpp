/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:59:52 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 19:59:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap::ClapTrap() {
	std::cout << "NinjaTrap Constructor called -> without name" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name): ClapTrap::ClapTrap(name) {
	hitPoints = 60;
	maxHitPoints = 60;
	energyPoints = 120;
	maxEnergyPoints = 120;
	level = 1;
	meleeAttackDamage = 60;
	rangedAttackDamage = 5;
	armorDamageReduction = 0;
}

NinjaTrap::~NinjaTrap() {
	std::cout << "NinjaTrap Destructor called" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & ref) {
	std::cout << "\n***** NinjaTrap::ninjaShoebox (ClapTrap) *****" << std::endl;
	meleeAttack(ref.getName());
	ref.takeDamage(getMeleeAttackDamage());
}

void	NinjaTrap::ninjaShoebox(ScavTrap & ref) {
	std::cout << "\n***** NinjaTrap::ninjaShoebox (ScavTrap) *****" << std::endl;
	meleeAttack(ref.getName());
	ref.takeDamage(getMeleeAttackDamage());
}

void	NinjaTrap::ninjaShoebox(FragTrap & ref) {
	std::cout << "\n***** NinjaTrap::ninjaShoebox (FragTrap) *****" << std::endl;
	meleeAttack(ref.getName());
	ref.takeDamage(getMeleeAttackDamage());
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & ref) {
	std::cout << "\n***** NinjaTrap::ninjaShoebox (NinjaTrap) *****" << std::endl;
	meleeAttack(ref.getName());
	ref.takeDamage(getMeleeAttackDamage());
}
