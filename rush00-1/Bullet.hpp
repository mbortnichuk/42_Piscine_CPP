/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:17:29 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:17:30 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

# include "Object.hpp"
# include "Champ.hpp"
# include "Enemy.hpp"
# include "Playground.hpp"

class Bullet:public Object {
public:
	Bullet(int n, std::string form);
	Bullet(Bullet const & src);
	~Bullet(void);
	Bullet* getBull(void)const;	
	int	getId(void)const;		
	int	getMax(void)const;
	void printIt(Playground& pl)const;
	void move(Playground& pl);
	void start(int xPos, int yPos, int inp);
	void checkDamage(Enemy* horde, int n, Playground& pl);
	void printCharge(Playground & pl);
	Bullet& operator=(Bullet const & rhs);
	int			checkMDisp(void);

private:
	Bullet(void);
	Bullet* mBull;
	int		 mMax;;
	int		 mId;
};

#endif
