/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:19:12 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:19:13 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() {
	return;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) {
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
	return;
}

AWeapon::AWeapon(AWeapon const &aWeapon) {
	*this = aWeapon;
	return;
}

AWeapon::~AWeapon() {
	return;
}

std::string const AWeapon::getName()const {
	return (this->name);
}

int AWeapon::getAPCost()const {
	return (this->apcost);
}

int AWeapon::getDamage()const {
	return (this->damage);
}

void AWeapon::setName(std::string const &newName) {
	this->name = newName;
	return;
}

void AWeapon::setAPCost(int newAPCost) {
	this->apcost = newAPCost;
	return;
}

void AWeapon::setDamage(int newDamage) {
	this->damage = newDamage;
	return;
}

AWeapon& AWeapon::operator=(AWeapon const &rhs) {
	std::cout << "Assignation operator AWeapon called" << std::endl;

	this->setName(rhs.getName());
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return *this;
}
