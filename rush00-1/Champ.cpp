/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Champ.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:41:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/18 17:41:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Champ.hpp"

Champ::Champ(void):Object() {
	return;
}

Champ::Champ(Playground & pl): Object((pl.getX() / 2), (pl.getY() - 5), 0, 0, 1, 3, "|/\\|") {
	return;
}

Champ::Champ(Champ const & src):Object(src) {
	*this = src;
	return;
}

Champ::~Champ(void) {
	return;
}

void Champ::printIt(Playground & pl)const {
	start_color();
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(5));
	if (mPosX >= 0 && mPosX <= pl.getX() && mPosY > 0 && mPosY < pl.getY() && mHP > 0)
		mvwprintw(pl.getWindow(), mPosY, mPosX, mForm.data());
	attroff(COLOR_PAIR(5));
}

void Champ::inputDir(int pl) {
	this->inp = 1;
	if (pl == 259 || pl == 258)
		pl == 258 ? mDirY += 1 : mDirY -= 1;
	else if (pl == 260 || pl == 261)
		pl == 261 ? mDirX += 2 : mDirX -= 2;
	if (mDirX < -2)
		mDirX = -2;
	if (mDirX > 2)
		mDirX = 2;
	if (mDirY < -1)
		mDirY = -1;
	if (mDirY > 1)
		mDirY = 1;
}

void Champ::move(Playground & pl) {
	this->inp = !this->inp;
	mPosY += (mDirY * mSpeed);
	mPosX += (mDirX * mSpeed);
	if (mPosY <= 0)
		mPosY = 1;
	if (mPosY >= pl.getY() -1)
		mPosY = pl.getY() - 1;
	if (mPosX <= 0)
		mPosX = 1;
	if (mPosX >= pl.getX() - 1)
		mPosX = pl.getX() - 2;
	if (this->inp)
		this->setDir(0, 0);
}

void Champ::checkEnemy(Enemy* enemy, int n, Playground & pl) {
	int center;
	int centerV;
	for (int i = 0;  i < n; i++) {
		if (enemy[i].getY() == mPosY) {
			center = enemy[i].getX() - (enemy[i].getSizeX() / 2);
			centerV = mPosX - (mSizeX / 2);
			centerV -= center;
			if (abs(centerV) <= mSizeX) {
				mHP -= 1;
				pl.setClr(2);
				pl.printBorder();
				enemy[i].die(pl);
				pl.setClr(0);
			}
		}
	}
}

Champ& Champ::operator=(Champ const & rhs) {
	Object::operator=(rhs);
	return (*this);
}

void Champ::printLives(Playground & pl)const {
	start_color();
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(18, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(18));
	mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 1, pl.getX() - 40 , "   __   ____________  ");
	mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 2, pl.getX() - 40 , "  / /  /  _/ __/ __/  []");
	mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 3 , pl.getX() - 40 , " / /___/ // _// _/  ");
	mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 4 , pl.getX() - 40 , "/____/___/_/ /___/    []");
	attroff(COLOR_PAIR(18));
	if (mHP == 3) {
		attron(COLOR_PAIR(5));
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY()  , pl.getX() - 10 , " _____ ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , "|___ / ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "  |_ \\ ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , " ___) |");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 4, pl.getX() - 10 , "|____/ ");
		attroff(COLOR_PAIR(5));
	} else if (mHP == 2) {
		attron(COLOR_PAIR(7));
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY(), pl.getX() - 10 , " ____  ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , "|___ \\ ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "  __) |");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , " / __/ ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 4, pl.getX() - 10 , "|_____|");
		attroff(COLOR_PAIR(7));
	} else {
		attron(COLOR_PAIR(6));
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY(), pl.getX() - 10 , "  _ ");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , " / |");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "/  |");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , " | |");
		mvwprintw(pl.getWindow(), pl.getY() - pl.getY() + 4, pl.getX() - 10 , " |_|");
		attroff(COLOR_PAIR(6));
		//refresh();
	}
}
