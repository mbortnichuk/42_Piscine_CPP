/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:13:37 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 16:13:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceShip.hpp"
#include "Field.hpp"

SpaceShip::SpaceShip() {
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	setDCh((char *)"<-[**]>");
	rsp = 500;
	rst = (rand() % rsp);
	setXpos(x - 1);
	setYpos(rand() % (y - 2) + 1);
	collide();
}

SpaceShip::SpaceShip(char *s) {
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	setDCh(s);
	setYpos(y / 2);
	setXpos(x - 2);
	setDCh(s);
	rsp = 100;
	rst = (rand() % rsp);
	collide();
}

SpaceShip::SpaceShip(const SpaceShip &obj) {
	*this = obj;
}

SpaceShip &SpaceShip::operator=(SpaceShip const &obj) {
	setDCh(obj.getDCh());
	setXpos(obj.getXpos());
	setYpos(obj.getYpos());
	return *this;
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::initiateBullets(GameCore arrBullets[], int count, char *bullet) {
	for (int i = 0;i < count; i++) {
		arrBullets[i].setDCh((char*)bullet);
		arrBullets[i].setCollided(true);
	}
}

void SpaceShip::shoot(GameCore arrBullets[]) {
	int i;

	i = 0;
	while (i < 10) {
		if (arrBullets[i].isCollided()) {
			system("afplay shoot.mp3 &");
			arrBullets[i].setXpos(getXpos() + 3);
			arrBullets[i].setYpos(getYpos());
			arrBullets[i].setCollided(false);
			break ;
		} else
			i++;
	}
}
