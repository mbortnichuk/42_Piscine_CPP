/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:20:11 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 17:20:12 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type): _name(name), _type(type) {
}

void	Zombie::announce()const {
	std::cout << "<" << _name << " (" << _type << ")> Braiiiiiiinnnssss..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "<" << _name << " (" << _type << ")> is died" << std::endl;
}
