/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 10:19:59 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 10:20:00 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{
	return ;
}

Enemy::Enemy( Enemy const &enemy )
{
	*this = enemy;
	return ;
}

Enemy::Enemy( int hp, std::string const &type )
{
	this->hp = hp;
	this->type = type;
}

Enemy::~Enemy()
{
	return ;
}

void Enemy::takeDamage( int dam)
{
	if (dam >= 0)
	{
		this->hp -= dam;
		if (this->hp < 0)
			this->hp = 0;
		std::cout << "take damage Enemy " << std::endl;
	}
	return ;
}

std::string const Enemy::getType() const
{
	return (this->type);
}

int Enemy::getHP() const
{
	return (this->hp);
}

void Enemy::setHP( int newHP )
{
	this->hp = newHP;
	if (this->hp < 0)
		this->hp = 0;
	return ;
}

void Enemy::setType( std::string const & newType )
{
	this->type = newType;
	return ;
}

Enemy& Enemy::operator=( Enemy const &rhs )
{
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());
	return ( *this );
}
