/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:20:46 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:20:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
private:
	std::string name;
	int actionPoints;
	AWeapon *aWeapon;
	Enemy *enemy;

public:
	Character();
	Character(Character const & character);
	Character(std::string const & name);
	~Character();
	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
	std::string const getName() const;
	int		getActionPoints() const;
	AWeapon	const *getAWeapon() const;
	Enemy	const *getEnemy() const;
	void	setName(std::string newName);
	void	setActionPoints(int newActionPoints);
	void	setAWeapon(AWeapon *newAWeapon);
	void	setEnemy(Enemy *newEnemy);
	Character &operator=(Character const &rhs);
};

std::ostream& operator<<(std::ostream &o, Character const &rhs);

#endif
