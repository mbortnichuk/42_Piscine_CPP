/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 22:03:49 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 22:03:50 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(): fixPoint(0) {
}

Fixed::Fixed(Fixed & a) {
	this->fixPoint = a.getRawBits();
}

Fixed::Fixed(const Fixed & a) {
	*this = a;
}

Fixed::Fixed(const int a) {
	this->fixPoint = (a << 8);
}

Fixed::Fixed(const float a) {
	this->fixPoint = std::roundf(a * 256.0f);
}

int Fixed::toInt(void)const {
	return (this->fixPoint >> 8);
}

float Fixed::toFloat(void)const {
	return (static_cast<float>((float)this->fixPoint / 256));
}

Fixed& Fixed::operator = (Fixed const & a) {
	this->fixPoint = a.fixPoint;
	return *this;
}

int Fixed::getRawBits(void)const {
	return ((this->fixPoint));
}

void Fixed::setRawBits(int const raw) {
	this->fixPoint = (raw << 8);
}

Fixed::~Fixed() {
}

std::ostream& operator << (std::ostream& os, Fixed const & a) {
	os << a.toFloat();
	return os;
}


Fixed& Fixed::operator++() {
	this->fixPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++*this;
	return *this;
}

Fixed& Fixed::operator--() {
	this->fixPoint--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--*this;
	return *this;
}

Fixed Fixed::operator+(Fixed a)const {
	Fixed tmp;
	tmp.fixPoint = this->fixPoint + a.fixPoint;
	return tmp;
}

Fixed Fixed::operator-(Fixed a)const {
	Fixed tmp;
	tmp.fixPoint = this->fixPoint - a.fixPoint;
	return tmp;
}

Fixed Fixed::operator*(Fixed a)const {
	Fixed tmp;
	tmp.fixPoint = ((this->fixPoint * a.fixPoint) >> 8);
	return tmp;
}

Fixed Fixed::operator/(Fixed a)const {
	Fixed tmp;
	tmp.fixPoint = ((this->fixPoint) << 8) / a.fixPoint;
	return tmp;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

bool Fixed::operator < (const Fixed &a) {
	return this->fixPoint < a.fixPoint ? true : false;
}

bool Fixed::operator > (const Fixed &a) {
	return this->fixPoint > a.fixPoint ? true : false;
}

bool Fixed::operator <= (const Fixed &a) {
	return this->fixPoint <= a.fixPoint ? true : false;
}

bool Fixed::operator >= (const Fixed &a) {
	return this->fixPoint >= a.fixPoint ? true : false;
}

bool Fixed::operator == (const Fixed &a) {
	return this->fixPoint == a.fixPoint ? true : false;
}

bool Fixed::operator != (const Fixed &a) {
	return this->fixPoint != a.fixPoint ? true : false;
}
