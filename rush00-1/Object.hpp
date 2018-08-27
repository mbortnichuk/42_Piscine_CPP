/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:34:20 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/18 14:34:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <unistd.h>
# include "Playground.hpp"
# include <string>

class Object {
public:
	Object();
	virtual ~Object();
	Object(int posX, int posY, int dirX, int dirY, int speed, int hp, std::string form);
	Object(Object const & src);
	
	int getX(void)const;
	int getY(void)const;
	int getDirX(void)const;
	int getDirY(void)const;
	int getSpeed(void)const;
	int getSizeX(void)const;
	int getHP(void)const;
	int getScore(void);
	std::string& getForm(void)const;

	void setHP(int i);
	void setPos(int x, int y);
	void setDir(int x, int y);
	void setSpeed(int s);
	void setForm(std::string form);
	void setScore(void);
	void setZeroScore(void);

	void printScore(Playground & pl)const;
	void explode(Playground & pl, int f);
	void move(Playground & pl);
	virtual void printIt(Playground & pl)const;
	virtual void collision(Object & obj);
	Object& operator=(Object const & rhs);
protected:
	int mPosX;
	int mPosY;
	int mDirX;
	int mDirY;
	int mSpeed;
	int mSizeX;
	int mHP;
	int static mScore;
	std::string mForm;
};

#endif
