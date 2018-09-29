/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DB.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:05:36 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/27 13:05:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DB.hpp"

DB::DB(void) {
	this->maxSize = 8;
	this->contactsAmount = 0;
	return;
}

DB::~DB(void) { return; }

int DB::getContactsAmount() { return (this->contactsAmount); }

void DB::setContactsAmount(int contacts) { this->contactsAmount = contacts; }

int DB::getFlg(void) { return (this->flg); }

void DB::setFlg(int flg) { this->flg = flg; }

PhoneBook DB::getContacts(int id) { return (this->db[id]); }

void DB::setDB(int id, PhoneBook db) {
	this->db[id] = db;
	return;
}
