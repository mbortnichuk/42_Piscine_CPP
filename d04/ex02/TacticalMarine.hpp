/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:08:09 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:08:12 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

# include "ISpaceMarine.hpp"
# include <iostream>
# include <string>

class TacticalMarine:public ISpaceMarine {
public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine const & src);
	~TacticalMarine(void);
	ISpaceMarine* clone(void) const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

	TacticalMarine& operator=(TacticalMarine const & rhs);	
};

#endif
