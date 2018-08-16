/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat & b): _name(b.getName()) {
	if (b.getGrade() < 1) {
		throw GradeTooHighException();
	} else if (b.getGrade() > 150) {
		throw GradeTooLowException();
	}
	_grade = b.getGrade();
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & b) {
	_grade = b.getGrade();
	return *this;
}

std::string const Bureaucrat::getName()const {
	return _name;
}

int Bureaucrat::getGrade()const {
	return _grade;
}

Bureaucrat::~Bureaucrat() {
}

std::ostream & operator << (std::ostream & os, Bureaucrat const & b) {
	return os << "<" << b.getName() << ">, bureaucrat grade <" << b.getGrade() << ">.";
}

Bureaucrat& Bureaucrat::operator++() {
	--_grade;
	if (_grade < 1) {
		throw GradeTooHighException();
	} else if (_grade > 150) {
		throw GradeTooLowException();
	}
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat tmp = *this;
	++*this;
	return tmp;
}

Bureaucrat& Bureaucrat::operator--() {
	++_grade;
	if (_grade < 1) {
		throw GradeTooHighException();
	} else if (_grade > 150) {
		throw GradeTooLowException();
	}
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat tmp = *this;
	++*this;
	return tmp;
}

const char* Bureaucrat::GradeTooHighException::what()const throw() {
	return ("The grade gets too high, max level 1");
}

const char* Bureaucrat::GradeTooLowException::what()const throw() {
	return ("The grade gets too low, min level = 150");
}

void Bureaucrat::increment() {
	++*this;
}

void Bureaucrat::decrement() {
	--*this;
}
