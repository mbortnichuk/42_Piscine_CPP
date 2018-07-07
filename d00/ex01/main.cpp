/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:56:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/13 19:56:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	print(std::string line) {
	if (line.length() > 10)
		std::cout << line.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << line;
}

void	addCommand(int& person_nbr, PhoneBook *phoneBookArr) {
	if (person_nbr == 8)
		std::cout << "No more places for contacts." << std::endl;
	else {
		std::cout << "Enter information for contact №" << (person_nbr + 1) << std::endl;
		phoneBookArr[person_nbr++].add();
	}
}

void	search(int& person_nbr, PhoneBook *phoneBookArr) {
	int id;
	std::string stringId;
	bool flg = true;

	for (int i = 0; i < person_nbr; i++) {
		std::cout << std::setw(10) << (i + 1) << "|";
		print(phoneBookArr[i].getFirstName());
		std::cout << "|";
		print(phoneBookArr[i].getLastName());
		std::cout << "|";
		print(phoneBookArr[i].getNickName());
		std::cout << std::endl;
	}
	while (flg) {
		std::cout << "Enter id from phone book: ";
		std::getline(std::cin, stringId);
		id = std::atoi(stringId.c_str());
		if (stringId.length() == 1 && id > 0 && id <= person_nbr) {
			flg = false;
			phoneBookArr[id - 1].printContact();
		}
		else {
			std::cout << "Incorrect data entered.\n";
		}
	}
}

int main(int ac, char **av) {
	int person_nbr = 0;
	std::string command;
	PhoneBook phoneBookArr[8];
	(void)av;

	if (ac == 1) {
		do {
			std::cout << "Enter command ${choose: ADD | SEARCH | EXIT}" << std::endl;
			std::getline(std::cin, command);
			if (command.compare("ADD") == 0)
				addCommand(person_nbr, phoneBookArr);
			else if (command.compare("SEARCH") == 0)
				search(person_nbr, phoneBookArr);
		} while (command.compare("EXIT") != 0);
	} else {
		std::cout << "Usage: ./phonebook" << std::endl;
	}
	return 0;
}
