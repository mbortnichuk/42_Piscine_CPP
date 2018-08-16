/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:12:50 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/15 14:12:51 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim {
public:
	Victim( std::string name );
	Victim( Victim const & victim );
	virtual ~Victim();
	virtual void getPolymorphed() const;
	virtual std::string getName( ) const;

protected:
	std::string name;
};

std::ostream &operator<<(std::ostream &o, Victim const &rhs);

#endif
