/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:46:36 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 12:46:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) {
	this->name = name;
	this->weapon = &weapon;
}

void	HumanA::attack()const {
	std::cout << this->name << " attacks with his " <<this->weapon->getType() << std::endl;
}
