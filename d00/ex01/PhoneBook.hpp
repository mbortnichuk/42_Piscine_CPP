/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:22:30 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 13:22:31 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_login;
	std::string	_postal_address;
	std::string	_email_address;
	std::string	_phone_number;
	std::string	_birthday_date;
	std::string	_favourite_meal;
	std::string	_underwear_color;
	std::string	_darkest_secret;
public:
	PhoneBook() {
	}
	std::string	getFirstName()const {
		return _first_name;
	}
	std::string getLastName()const {
		return _last_name;
	}
	std::string getNickName()const {
		return _nickname;
	}
	void	add(void);
	void	printContact(void);
	~PhoneBook() {
	}
};

#endif
