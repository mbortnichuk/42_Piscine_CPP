/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:06:46 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/27 13:06:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DB.hpp"

size_t strlen(std::string str) {
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

int isDigit(int n) {
	if ((n >= '1') && (n <= '9'))
		return 1;
	return 0;
}

int atoi(std::string str) {
	int i = 0;
	int res = 0;

	while (isDigit(str[i]) == 1) {
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return res;
}

std::string getText() {
	std::string inp;
	if (std::getline(std::cin, inp))
		return inp;
	std::cout << "Cannot read input.\n";
	std::exit(-1);
}

DB addCommand(DB myDB) {
	int counter = myDB.getContactsAmount();
	PhoneBook temp;

	if (myDB.getContactsAmount() > 7) {
		std::cout << "Phonebook is full." << std::endl;
		return myDB;
	}
	std::cout << "Enter your first name!" << std::endl;
	temp.setFirstName(getText());
	std::cout << "Enter your last name!" << std::endl;
	temp.setLastName(getText());
	std::cout << "Enter your nickname!" << std::endl;
	temp.setNickname(getText());
	std::cout << "Enter your login!" << std::endl;
	temp.setLogin(getText());
	std::cout << "Enter your postal address!" << std::endl;
	temp.setPostalAddress(getText());
	std::cout << "Enter your email address!" << std::endl;
	temp.setEmailAddress(getText());
	std::cout << "Enter your phone number!" << std::endl;
	temp.setPhoneNumber(getText());
	std::cout << "Enter your birthday date!" << std::endl;
	temp.setBirthdayDate(getText());
	std::cout << "Enter your favorite meal!" << std::endl;
	temp.setFavoriteMeal(getText());
	std::cout << "Enter your underwear color!" << std::endl;
	temp.setUnderwearColor(getText());
	std::cout << "Enter your darkest secret!" << std::endl;
	temp.setDarkestSecret(getText());
	myDB.setDB(counter, temp);
	myDB.setContactsAmount(myDB.getContactsAmount() + 1);
	return myDB;
}

void column(std::string str) {
	size_t i = 0;
	while (i < 10) {
		if ( i > strlen(str) - 1)
			std::cout << " ";
		if (i == 9 && strlen(str) > 9)
			std::cout << ".";
		else
			std::cout << str[i];
		i++;
	}
	std::cout << "|";
}

void searchCommand(DB myDB) {
	int i = 0;
	std::string comm;
	if (myDB.getContactsAmount() == 0) {
		std::cout << "There is no contacts in Phonebook." << std::endl;
		return;
	}
	std::cout << "id        |first name|last name |nickname  |" << std::endl;
	while (i < myDB.getContactsAmount()) {
		std::cout << i + 1 << "         |";
		PhoneBook temp = myDB.getContacts(i);
		column(temp.getFirstName());
		column(temp.getLastName());
		column(temp.getNickname());
		std::cout << "\n";
		i++;
	}
	std::cout << "Enter contact id." << std::endl;
	while (1) {
		comm = getText();
		if ((strlen(comm)) > 1)
			std::cout << "Incorrect id." << std::endl;
		else if (comm[0] < '1' && comm[0] > '9')
			std::cout << "Incorrect id." << std::endl;
		else if (comm[0] - 48 > myDB.getContactsAmount())
			std::cout << "Incorrect id." << std::endl;
		else {
			int id  = atoi(comm);
			if (id > 0) {
				PhoneBook temp = myDB.getContacts(id - 1);
				temp.contactInfo();
				break;
			}
			else
				std::cout << "Incorrect id." << std::endl;
		}
	}
	return;
}

DB command(std::string com, DB myDB) {
	if (com == "EXIT")
		myDB.setFlg(-1);
	else if (com == "ADD")
		myDB = addCommand(myDB);
	else if (com == "SEARCH")
		searchCommand(myDB);
	else {
		std::cout << "Unknown command." << std::endl;
		std::cout << "Available commands [ADD SEARCH EXIT]" << std::endl;
	}
	return myDB;
}

int main(void) {
	DB myDB;
	std::string comm;
	while (1) {
		comm = getText();
		myDB = command(comm, myDB);
		if (myDB.getFlg() == -1)
			return 1;
	}
}
