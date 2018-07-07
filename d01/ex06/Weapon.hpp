/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:47:00 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 12:47:03 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon() {
	}
	Weapon(std::string str);
	const std::string& getType();
	void	setType(std::string str);
	~Weapon() {
	}
};

#endif
