/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:53:33 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:53:34 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
# define ICHARACTER_H

# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual void				equip(AMateria *materia) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter const &target) = 0;

		virtual std::string const	&getName(void) const = 0;
};

#endif
