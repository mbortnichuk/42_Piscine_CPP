/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DB.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:05:40 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/27 13:05:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DB_HPP
# define DB_HPP

# include <iostream>
# include "PhoneBook.hpp"

class DB {
public:
	DB(void);
	~DB(void);
	int getContactsAmount();
	void setContactsAmount(int contacts);
	PhoneBook getContacts(int id);
	int getFlg(void);
	void setFlg(int flg);
	void setDB(int ad, PhoneBook db);
private:
	PhoneBook db[8];
	int maxSize;
	int contactsAmount;
	int flg;
};

#endif
