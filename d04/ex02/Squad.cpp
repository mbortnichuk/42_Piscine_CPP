/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:14:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:14:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include <iostream>

Squad::Squad(void): _squad(0), _count(0) {
	return;
}

Squad::Squad(Squad & src) {
	*this = src;
	return;
}

Squad::~Squad(void) {

	if (this->_squad)
	{
		for (int i = 0; i < this->_count; ++i)
		{
			if (this->_squad[i])
				delete this->_squad[i];
		}
		delete [] this->_squad;
	}
	return;
}

int				Squad::getCount(void) const {
	return(this->_count);	
}

ISpaceMarine*	Squad::getUnit(int i) {
	if (i >= 0 && i <= this->_count)
		return (this->_squad[i]);
	return (0);
}

int				Squad::push(ISpaceMarine* sm) {
	if (!sm)
		return (this->_count);
	if (this->_squad)
	{
		for (int i = 0; i < this->_count; ++i)
		{
			if (this->_squad[i] == sm)
				return (this->_count);
		}
	}
	ISpaceMarine **news = new ISpaceMarine*[this->_count + 1];	
	if (this->_squad)
	{
		for (int e = 0; e < this->_count; ++e)
		{
			if (this->_squad[e])
				news[e] = this->_squad[e];
		}
		delete [] this->_squad;
	}
	news[this->_count] = sm;
	this->_count += 1;
	this->_squad = news;
	return (this->_count);
}

Squad&			Squad::operator=(Squad & rhs) {
	for (int i = 0; i < rhs.getCount(); ++i)
		this->push(rhs.getUnit(i));
	this->_count = rhs.getCount();
	return (*this);
}