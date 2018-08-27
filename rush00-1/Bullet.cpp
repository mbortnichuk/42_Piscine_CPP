/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:43:41 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/21 16:43:42 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(int n, std::string form) {
	mMax = n;
	mId = 0;
	mBull = new Bullet[n]();

	for (int i = 0; i < n; i++) {
		mBull[i].setForm(form);
		mBull[i].setDir(0, -1);
		mBull[i].setHP(0);
	}
}

Bullet::Bullet(void):Object() {
	mMax = 0;
	mId = 0;
	mBull = NULL;
	mHP = 0;

	return ;
}

Bullet::Bullet(Bullet const & src):Object(src) {
	*this = src;
	return ;
}

Bullet::~Bullet(void) {
	if (mBull) {
		delete[] mBull;
		mBull = NULL;
	}
	return ;
}

Bullet* Bullet::getBull(void)const {
	return (mBull);
}

int Bullet::getId(void)const {
	return (mId);
}

int Bullet::getMax(void)const {
	return (mMax);
}

int Bullet::checkMDisp(void) {
	int i = 0;

	while (i < mMax) {
		if (mBull[i].getHP() == 0)
			return i;
		i++;
	}
	return -1;
}

void Bullet::start(int xPos, int yPos, int inp) {
	int i = checkMDisp();

	if (inp == 10 && i >= 0) {
		mBull[i].setPos(xPos + 1, yPos - 1);
		mBull[i].setHP(1);
	}
}

void Bullet::checkDamage(Enemy* enemy, int n, Playground & pl) {
	int center;
	int centerV;

	for (int i = 0; i < mMax; i++) {
		for (int j = 0; j < n; j++) {
			if (mBull[i].getHP() > 0 && enemy[j].getHP() > 0) {
				if (abs(mBull[i].getY() - enemy[j].getY()) <= 3) {
					center = enemy[i].getX() - (enemy[j].getSizeX() / 3);
					centerV = mBull[i].getX();
					centerV -= center;
					if (abs(centerV) <= 2) {
						mBull[i].explode(pl, 1);
						enemy[j].die(pl);
					}
				}
			}
		}
	}
}

void Bullet::printIt(Playground & pl)const {
	start_color();
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	for (int i = 0; i < mMax; i++) {
		mBull[i].Object::printIt(pl);
	}
	attron(COLOR_PAIR(7));
}

void Bullet::move(Playground & pl) {
	for (int i = 0; i < mMax; i++) {
		if (mBull[i].getY() < 0) {
			mBull[i].setHP(0);
		}
		mBull[i].Object::move(pl);
	}
}

Bullet& Bullet::operator=(Bullet const & rhs) {
	Object::operator=(rhs);
	return (*this);
}

void Bullet::printCharge(Playground & pl) {
	int i = 0;
	int min = 0;

	while (i < mMax) {
		if (mBull[i].getHP() == 0)
			min++;
		i++;
	}
	start_color();
	attron(COLOR_PAIR(18));
	mvwprintw(pl.getWindow(), pl.getY() - 19 + i , pl.getX() - 46 , "   ___  ____  _______ __");
	mvwprintw(pl.getWindow(), pl.getY() - 18 + i , pl.getX() - 46 , "  / _ \\/ __ \\/ ___/ //_/  []");
	mvwprintw(pl.getWindow(), pl.getY() - 17 + i , pl.getX() - 46 , " / , _/ /_/ / /__/ ,<   ");
	mvwprintw(pl.getWindow(), pl.getY() - 16 + i , pl.getX() - 46 , "/_/|_|\\____/\\___/_/|_|    [] ");
	attroff(COLOR_PAIR(18));
	if (min > mMax - (mMax / 3) || min == mMax)
		attron(COLOR_PAIR(5));
	else if (min > mMax - (2 * mMax / 3) || min == mMax / 2)
		attron(COLOR_PAIR(7));
	else
		attron(COLOR_PAIR(6));

	for (i = 1; i < mMax + 1; i++) {
		if (i == mMax)
			mvwprintw(pl.getWindow(), pl.getY() - 16 + i, pl.getX() - 14, "|____________");
		else
			mvwprintw(pl.getWindow(), pl.getY() - 16 + i, pl.getX() - 14, "| ");
	}
	for (i = 1; i < mMax + 1; i++)
		mvwprintw(pl.getWindow(), pl.getY() - 16 + i, pl.getX() - 2, "| ");

	while (min > 0) {
		mvwprintw(pl.getWindow(), pl.getY() - mMax - 13 - (min - mMax), pl.getX() - 12, "#########");
		min++;
	}

	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
}
