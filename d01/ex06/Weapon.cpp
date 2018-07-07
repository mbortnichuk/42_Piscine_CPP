/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:46:25 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 12:46:26 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) : type(str) {
}

const std::string& Weapon::getType() {
	std::string const &ref = type;

	return ref;
}

void	Weapon::setType(std::string str) {
	type = str;
}
