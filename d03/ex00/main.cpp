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

	return 0;
}
