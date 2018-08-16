/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:13:03 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:13:03 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim{
public:
	Peon( Peon const & peon );
	Peon( std::string name );
	~Peon();
	void getPolymorphed( ) const;
	std::string getName( ) const;

private:
	std::string name;
};

std::ostream &operator<<(std::ostream &o, Peon const &rhs);

#endif
