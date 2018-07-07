/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:54:15 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 18:54:17 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(): fixPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed & a) {
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator = (Fixed& a) {
	std::cout << "Assignation operator called" << std::endl;
	this->fixPoint = a.getRawBits();
	return *this;
}

int Fixed::getRawBits(void)const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixPoint;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixPoint = raw;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}
