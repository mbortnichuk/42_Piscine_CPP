/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameCore.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:40:35 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 15:40:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameCore.hpp"

GameCore::GameCore() {
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	dCh = (char*)".";
	setYpos(rand() % (y - 2) + 1);
	setXpos(rand() % (x - 2) + 1);
	collided = false;
}

GameCore::GameCore(GameCore const & obj) {
	*this = obj;
}

GameCore &GameCore::operator=(GameCore const & obj) {
	setDCh(obj.getDCh());
	setXpos(obj.getXpos());
	setYpos(obj.getYpos());

	return *this;
}

GameCore::~GameCore() {
}

void	GameCore::collide() {
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	rst = (rand() % rsp + 50);
	collided = true;
	setXpos(x - 7);
	setYpos(rand() % (y - 2) + 1);
}


int GameCore::getXpos()const {return xpos;}

int GameCore::getYpos()const {return ypos;}

char *GameCore::getDCh()const {return dCh;}

int GameCore::getRSpeed()const {return rsp;}

int GameCore::getRespawnTime()const {return rst;}

bool GameCore::isCollided()const {return collided;}


void GameCore::setXpos(int xpos) {GameCore::xpos = xpos;}

void GameCore::setYpos(int ypos) {GameCore::ypos = ypos;}

void GameCore::setDCh(char *dCh) {GameCore::dCh = dCh;}

void GameCore::setRSpeed(int rsp) {GameCore::rsp = rsp;}

void GameCore::setRespawnTime(int rst) {GameCore::rst = rst;}

void GameCore::setCollided(bool collided) {GameCore::collided = collided;}
