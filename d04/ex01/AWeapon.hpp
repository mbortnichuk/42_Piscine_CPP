/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:19:16 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:19:17 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon {
private:
	std::string name;
	int apcost;
	int damage;
public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & aWeapon);
	virtual ~AWeapon();

	std::string const getName()const;
	int getAPCost()const;
	int getDamage()const;

	void setName(std::string const & newName);
	void setAPCost(int newAPCost);
	void setDamage(int newDamage);

	virtual void attack()const = 0;

	AWeapon &operator=(AWeapon const &rhs);
};

#endif
