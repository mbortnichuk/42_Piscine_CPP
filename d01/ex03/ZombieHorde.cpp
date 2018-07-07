/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:51:23 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 18:51:24 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
	nbr = n;
	zombies = new Zombie[n];
}

ZombieHorde::~ZombieHorde() {
	delete[] zombies;
}

void	ZombieHorde::announce()const {
	for (int i = 0; i < nbr; i++)
		zombies[i].announce();
}
