/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:38:09 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/19 16:38:10 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	srand(time(0));
	FragTrap player("Player");
	player.rangedAttack("Toto");
	player.meleeAttack("Toto");
	player.takeDamage(50);
	player.beRepaired(50);
	player.takeDamage(100);
	player.beRepaired(100);
	player.vaulthunter_dot_exe("Chak");
	player.vaulthunter_dot_exe("Chak");
	player.vaulthunter_dot_exe("Chak");
	player.vaulthunter_dot_exe("Chak");

	ScavTrap newComer("Hulk");
	newComer.rangedAttack("Hulk");
	newComer.meleeAttack("Hulk");
	newComer.takeDamage(50);
	newComer.beRepaired(50);
	newComer.takeDamage(100);
	newComer.beRepaired(100);
	newComer.challengeNewcomer();
	newComer.challengeNewcomer();
	newComer.challengeNewcomer();
	newComer.challengeNewcomer();

	return 0;
}
