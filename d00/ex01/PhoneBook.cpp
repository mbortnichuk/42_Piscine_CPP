/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:22:12 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 13:22:14 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add(void) {
	std::cout << "Enter your first name!" << std::endl;
	std::getline(std::cin, this->_first_name);
	std::cout << "Enter your last name!" << std::endl;
	std::getline(std::cin, this->_last_name);
	std::cout << "Enter your nickname!" << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter your login!" << std::endl;
	std::getline(std::cin, this->_login);
	std::cout << "Enter your postal address!" << std::endl;
	std::getline(std::cin, this->_postal_address);
	std::cout << "Enter your email address!" << std::endl;
	std::getline(std::cin, this->_email_address);
	std::cout << "Enter your phone number!" << std::endl;
	std::getline(std::cin, this->_phone_number);
	std::cout << "Enter your birthday date!" << std::endl;
	std::getline(std::cin, this->_birthday_date);
	std::cout << "Enter your favourite meal!" << std::endl;
	std::getline(std::cin, this->_favourite_meal);
	std::cout << "Enter your underwear color!" << std::endl;
	std::getline(std::cin, this->_underwear_color);
	std::cout << "Enter your darkest secret!" << std::endl;
	std::getline(std::cin, this->_darkest_secret);
}

void	PhoneBook::printContact(void) {
	std::cout << "*********************************************" << std::endl;
	std::cout << "first name: " << _first_name << std::endl;
	std::cout << "last name: " << _last_name << std::endl;
	std::cout << "nickname: " << _nickname << std::endl;
	std::cout << "login: " << _login << std::endl;
	std::cout << "postal address: " << _postal_address << std::endl;
	std::cout << "email address: " << _email_address << std::endl;
	std::cout << "phone number: " << _phone_number << std::endl;
	std::cout << "birthday date: " << _birthday_date << std::endl;
	std::cout << "favourite meal: " << _favourite_meal << std::endl;
	std::cout << "underwear color: " << _underwear_color << std::endl;
	std::cout << "darkest secret: " << _darkest_secret << std::endl;
}
