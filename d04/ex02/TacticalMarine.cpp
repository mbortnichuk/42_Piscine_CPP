/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:08:05 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:08:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) {
	std::cout << "Tactical Marine ready for battle" << std::endl;
	return;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src) {
	(void)src;
	return;
}

TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh..." << std::endl;
	return;
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const & rhs) {
	(void)rhs;
	return (*this);
}

ISpaceMarine* TacticalMarine::clone(void) const {
	return (new TacticalMarine);
}

void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
	return;
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
	return;
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
	return;
}
