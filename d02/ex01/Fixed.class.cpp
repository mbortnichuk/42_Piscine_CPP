/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:28:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 19:28:54 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(): fixPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed & a) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixPoint = a.getRawBits();
}

Fixed::Fixed(const Fixed & a) {
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed(const int a) {
	std::cout << "Int constructor called" << std::endl;
	this->fixPoint = (a << 0);
}

Fixed::Fixed(const float a) {
	std::cout << "Float constructor called" << std::endl;
	this->fixPoint = std::roundf(a * 256.0f);
}

int Fixed::toInt(void)const {
	return (this->fixPoint >> 0);
}

float Fixed::toFloat(void)const {
	return (static_cast<float>((float)this->fixPoint / 256));
}

Fixed& Fixed::operator = (Fixed const & a) {
	std::cout << "Assignation operator called" << std::endl;
	this->fixPoint = a.fixPoint;
	return *this;
}

int Fixed::getRawBits(void)const {
	std::cout << "getRawBits member function called" << std::endl;
	return ((this->fixPoint));
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixPoint = (raw << 8);
}

Fixed::~Fixed() {
	std::cout << "Default destructor called" << std::endl;
}

std::ostream& operator << (std::ostream& os, Fixed const & a) {
	os << a.toFloat();
	return os;
}
