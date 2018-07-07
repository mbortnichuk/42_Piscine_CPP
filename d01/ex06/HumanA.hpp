/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:46:41 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 12:46:42 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	Weapon* weapon;
	std::string name;
public:
	HumanA() {
	}
	HumanA(std::string name, Weapon& weapon);
	void	attack()const;
	~HumanA() {
	}
};

#endif
