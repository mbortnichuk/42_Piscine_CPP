/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jet.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:46:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/21 13:46:35 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Jet.hpp"

Jet::Jet(int n, std::string form) {
	mMax = n;
	mId = 0;
	mJets = new Jet[n]();

	for (int i = 0; i < n; i++) {
		mJets[i].setForm(form);
		mJets[i].setDir(0, -1);
		mJets[i].setHP(0);
	}
}

Jet::Jet(void):Object() {
	mMax = 0;
	mId = 0;
	mJets = NULL;
	mHP = 0;
	return ;
}

Jet::Jet(Jet const & src):Object(src) {
	*this = src;
	return ;
}

Jet::~Jet(void) {
	if (mJets) {
		delete[] mJets;
		mJets = NULL;
	}
	return ;
}

Jet* Jet::getJet(void)const {
	return (mJets);
}

int Jet::getId(void)const {
	return (mId);
}

int Jet::getMax(void)const {
	return (mMax);
}

int Jet::checkMDisp(void) {
	int i = 0;
	while (i < mMax) {
		if (mJets[i].getHP() == 0)
			return i;
		i++;
	}
	return -1;
}

void Jet::start(int xPos, int yPos, int inp) {
	int i = checkMDisp();

	if (inp == 32 && i >= 0) {
		mJets[i].setPos(xPos + 1, yPos - 1);
		mJets[i].setHP(1);
	}
}

void Jet::checkDamage(Enemy* enemy, int n, Playground & pl) {
	int center;
	int centerV;

	for (int i = 0; i < mMax; i++) {
		for (int j = 0; j < n; j++) {
			if (mJets[i].getHP() > 0 && enemy[j].getHP() > 0) {
				if (abs(mJets[i].getY() - enemy[j].getY()) <= 3) {
					center = enemy[j].getX() + (enemy[j].getSizeX() / 3);
					centerV = mJets[i].getX();
					centerV -= center;
					if (abs(centerV) <= 2) {
						mJets[i].collision(enemy[j]);
						mJets[i].explode(pl, 1);
						enemy[j].die(pl);
						mJets[i].setHP(0);
					}
				}
			}
		}
	}
}

void Jet::printIt(Playground & pl)const {
	start_color();
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	for (int i = 0; i < mMax; i++)
		mJets[i].Object::printIt(pl);
	attroff(COLOR_PAIR(7));
}

void Jet::move(Playground& pl) {
	for (int i = 0; i < mMax; i++) {
		if (mJets[i].getY() < 0) {
			mJets[i].setHP(0);
		}
		mJets[i].Object::move(pl);
	}
}

Jet& Jet::operator=(Jet const & rhs) {
	Object::operator=(rhs);
	return (*this);
}

void Jet::printCharge(Playground & pl) {
	int i = 0;
	int min = 0;

	while (i < mMax) {
		if (mJets[i].getHP() == 0)
			min++;
		i++;
	}
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));

	mvwprintw(pl.getWindow(), pl.getY() - 16 + i , pl.getX() - 46 , "   ___   __  _____  _______ ");
	mvwprintw(pl.getWindow(), pl.getY() - 15 + i , pl.getX() - 46 , "  / _ | /  |/  /  |/  / __ \\ []");
	mvwprintw(pl.getWindow(), pl.getY() - 14 + i , pl.getX() - 46 , " / __ |/ /|_/ / /|_/ / /_/ /");
	mvwprintw(pl.getWindow(), pl.getY() - 13 + i , pl.getX() - 46 , "/_/ |_/_/  /_/_/  /_/\\____/  []");
	attroff(COLOR_PAIR(18));
	if (min > mMax - (mMax / 3))
		attron(COLOR_PAIR(5));
	else if (min > mMax - (2 * mMax / 3))
		attron(COLOR_PAIR(7));
	else
		attron(COLOR_PAIR(6));

	for (i = 1; i < mMax + 1; i++) {
		if (i == mMax)
			mvwprintw(pl.getWindow(), pl.getY() - 12 + i, pl.getX() - 14, "|____________");
		else
			mvwprintw(pl.getWindow(), pl.getY() - 12 + i, pl.getX() - 14, "| ");
	}

	for (i = 1; i < mMax; i++)
		mvwprintw(pl.getWindow(), pl.getY() - 12 + i, pl.getX() - 2, "| ");

	while (min > 0) {
		mvwprintw(pl.getWindow(), pl.getY() - mMax - 1 - (min - mMax), pl.getX() - 12, "#########");
		min--;
	}
	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
}

  //    __
  //   / _ \
  //  / __ |
  // / / \ \