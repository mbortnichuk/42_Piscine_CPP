/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:08:44 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:08:46 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_SPACE_MARINE_HPP
# define I_SPACE_MARINE_HPP

class ISpaceMarine {
public:
	virtual ~ISpaceMarine(void){};
	virtual ISpaceMarine* clone(void)const = 0;
	virtual void battleCry()const = 0;
	virtual void rangedAttack()const = 0;
	virtual void meleeAttack()const = 0;
};

#endif
