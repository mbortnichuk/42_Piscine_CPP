/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:27 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:12:29 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>

#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer {
public:
	Sorcerer(std::string const & name, std::string const & title);
	Sorcerer(Sorcerer const & sorcerer);
	~Sorcerer();
	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const & victim) const;
	void polymorph(Peon const & peon) const;

protected:
	std::string name;
	std::string title;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
