/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:20:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/29 17:25:04 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int		main(void) {
	srand(time(0));

	std::cout << "***** Zombie in Stack *****" << std::endl;
	Zombie statZomb("statZomb", "z1");
	statZomb.announce();

	std::cout << "\n***** Zombie in Heap *****" << std::endl;
	Zombie* dynamZomb = new Zombie("dynamZomb", "z2");
	dynamZomb->announce();

	std::cout << "\n***** ZombieEvent -> randomZombie *****" << std::endl;
	ZombieEvent newzomb;
	Zombie* zomb1 = newzomb.randomZombie();
	Zombie* zomb2 = newzomb.randomZombie();
	Zombie* zomb3 = newzomb.randomZombie();

	std::cout << "\n***** ZombieEvent::newZombie *****" << std::endl;
	ZombieEvent	LOL;
	LOL.setZombieType("oldZomb");
	Zombie* newZom = LOL.newZombie("newZomb");
	newZom->announce();

	std::cout << "\n***** delete Zombie from Heap *****" << std::endl;
	delete dynamZomb;
	delete zomb1;
	delete zomb2;
	delete zomb3;
	delete newZom;

	std::cout << "\n***** delete Zombie from Stack && end prog *****" << std::endl;
	return 0;
}
