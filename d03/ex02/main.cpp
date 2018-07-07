/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:51:28 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 12:51:29 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	srand(time(0));
	ScavTrap b("ScavTrap");
	FragTrap c("FragTrap");

	std::cout << "***** ScavTrap *****\n" << std::endl;
	std::cout << b.getName() << std::endl;
	std::cout << b.getHitPoints() << std::endl;
	std::cout << b.getMaxHitPoints() << std::endl;
	std::cout << b.getEnergyPoints() << std::endl;
	std::cout << b.getMaxEnergyPoints() << std::endl;
	std::cout << b.getLevel() << std::endl;
	std::cout << b.getMeleeAttackDamage() << std::endl;
	std::cout << b.getArmorDamageReduction() << std::endl;

	std::cout << "\n***** rangedAttack -> <ScavTrap> attacks <FragTrap> *****" << std::endl;
	b.rangedAttack("FragTrap");
	c.takeDamage(b.getRangedAttackDamage());

	std::cout << "\n***** meleeAttack -> <ScavTrap> attacks <FragTrap> *****" << std::endl;
	b.meleeAttack("FragTrap");
	c.takeDamage(b.getMeleeAttackDamage());
	c.beRepaired(40);

	std::cout << "\n***** challengeNewcomer *****" << std::endl;
	b.challengeNewcomer();
	b.challengeNewcomer();
	b.challengeNewcomer();
	b.challengeNewcomer();
	b.challengeNewcomer();

	std::cout << "\n\n***** FragTrap *****" << std::endl;
	std::cout << c.getName() << std::endl;
	std::cout << c.getHitPoints() << std::endl;
	std::cout << c.getMaxHitPoints() << std::endl;
	std::cout << c.getEnergyPoints() << std::endl;
	std::cout << c.getMaxEnergyPoints() << std::endl;
	std::cout << c.getLevel() << std::endl;
	std::cout << c.getMeleeAttackDamage() << std::endl;
	std::cout << c.getArmorDamageReduction() << std::endl;

	std::cout << "\n***** rangedAttack -> <FragTrap> attacks <ScavTrap> *****" << std::endl;
	c.rangedAttack("ScavTrap");
	b.takeDamage(c.getRangedAttackDamage());

	std::cout << "\n***** meleeAttack -> <FragTrap> attacks <ScavTrap> *****" << std::endl;
	c.meleeAttack("ScavTrap");
	b.takeDamage(c.getMeleeAttackDamage());
	b.beRepaired(50);

	std::cout << "\n***** vaulthunter_dot_exe *****" << std::endl;
	c.vaulthunter_dot_exe("Bob");
	c.vaulthunter_dot_exe("Bob");
	c.vaulthunter_dot_exe("Bob");
	c.vaulthunter_dot_exe("Bob");
	c.vaulthunter_dot_exe("Bob");

	return 0;
}
