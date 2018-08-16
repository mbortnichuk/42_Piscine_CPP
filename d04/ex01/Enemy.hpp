/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:20:02 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:20:03 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy {
private:
	std::string type;
	int hp;

public:
	Enemy();
	Enemy(Enemy const & enemy);
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	std::string const	getType() const;
	int					getHP() const;
	void				setType(std::string const & newType);
	void				setHP(int newHP);
	virtual void takeDamage(int);
	Enemy &operator=(Enemy const &rhs);
};

#endif
