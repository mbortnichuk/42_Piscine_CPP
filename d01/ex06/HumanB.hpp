/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:46:52 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 12:46:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
private:
	Weapon* weapon;
	std::string name;
public:
	HumanB() {
	}
	HumanB(std::string name);
	HumanB(std::string name, Weapon& weapon);
	void	attack()const;
	void	setWeapon(Weapon& weapon);
	~HumanB() {
	}
};

#endif
