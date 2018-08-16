/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:07:52 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:07:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SQUAD_HPP
# define I_SQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad {
public:
	virtual ~ISquad(void) {
	}
	virtual int getCount()const = 0;
	virtual ISpaceMarine* getUnit(int) = 0;
	virtual int push(ISpaceMarine*) = 0;
};

#endif
