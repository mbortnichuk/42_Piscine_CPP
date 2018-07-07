/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 18:48:05 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 18:48:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actions.hpp"

Actions::Actions() {
}

Actions::Actions(Actions const &obj) {
	*this = obj;
}

Actions &Actions::operator=(Actions const &obj) {
	set_action(obj.getActions());
	return *this;
}

Actions::~Actions() {
}
int Actions::getActions()const {
	return action;
}

void Actions::set_action(int action) {
	Actions::action = action;
}

void Actions::setAction(int ch) {
	if (ch == KEY_LEFT || ch == KEY_RIGHT || ch == KEY_UP || ch == KEY_DOWN || ch == ' ' || ch == 'q') {
		set_action(ch);
	} else {
		set_action('p');
	}
}

void Actions::checkCollision(Champ *c1, SpaceShip s1[], GameCore champBullets[], GameCore enemyBullets[]) {
	int y, x;
	x = c1->getXpos();
	y = c1->getYpos();
	for (int i = 0; i < 20; i++) {
		if (!s1[i].isCollided() && !c1->isCollided()) {
			if ((x - s1[i].getXpos()) > -11 && (x - s1[i].getXpos()) < 7 && y == s1[i].getYpos()) {
				c1->collide();
				s1[i].collide();
				c1->setScore(c1->getScore() - 20);
				system("afplay boom.mp3 &");
			}
		}
	}
	getmaxyx(stdscr, y, x);
	if (c1->getYpos() == 0 || c1->getYpos() == y - 1)
		c1->collide();
	for (int i = 0; i < 20; i++)
		if (!s1[i].isCollided())
			if (s1[i].getXpos() < -1) {
				s1[i].collide();
				if (c1->getLevel() == 3)
					c1->setScore(c1->getScore() - 2);
			}
	for (int i = 0; i < 10; i++) {
		if (!champBullets[i].isCollided()) {
			for (int j = 0; j < 20; j++) {
				if (!s1[j].isCollided()) {
					if (champBullets[i].getYpos() == s1[j].getYpos()) {
						if (champBullets[i].getXpos() == s1[j].getXpos()
						    || champBullets[i].getXpos() == s1[j].getXpos() - 1
						    || champBullets[i].getXpos() == s1[j].getXpos() - 2
							|| champBullets[i].getXpos() == s1[j].getXpos() - 3) {
							system("afplay boom.mp3 &");
							champBullets[i].setCollided(true);
							s1[j].collide();
							c1->setScore(c1->getScore() + 10);
						}
					}
				}
			}
			if (champBullets[i].getXpos() > x - 2)
				champBullets[i].setCollided(true);
		}
	}
	for (int i = 0; i < 200; i++) {
		if (!enemyBullets[i].isCollided()) {
			if (enemyBullets[i].getYpos() == c1->getYpos()) {
				if (enemyBullets[i].getXpos() == c1->getXpos()
				    || enemyBullets[i].getXpos() == c1->getXpos() - 1
				    || enemyBullets[i].getXpos() == c1->getXpos() - 2
					|| enemyBullets[i].getXpos() == c1->getXpos() - 3) {
					system("afplay boom.mp3 &");
					enemyBullets[i].setCollided(true);
					c1->collide();
					c1->setScore(c1->getScore() - 20);
				}
			}
			if (enemyBullets[i].getXpos() < 0)
				enemyBullets[i].setCollided(true);
		}
	}
	if (c1->getScore() < 0)
		c1->setLive(0);
}

bool Actions::applyAct(Champ *p, SpaceShip s[], GameCore stars[], GameCore champBullets[], GameCore enemyBullets[], GameCore explode[]) {
	int row, col;
	static int starcount = 0;
	getmaxyx(stdscr, row, col);
	if (p->getScore() >= 50)
		p->setLevel(p->getScore());
	switch (action) {
		case KEY_LEFT:
			if ((p->getXpos() > 1 && p->getYpos() > 5) || (p-> getXpos() > 25 && p->getYpos() > 1))
				p->setXpos(p->getXpos() - 3);
			break;
		case KEY_RIGHT:
			if (p->getXpos() < col - 13)
				p->setXpos(p->getXpos() + 3);
			break;
		case KEY_UP:
			if ((p->getYpos() > 7 && p->getXpos() < 24) || (p->getXpos() > 24 && p->getYpos() > 1))
				p->setYpos(p->getYpos() - 1);
			break;
		case KEY_DOWN:
			if (p->getYpos() < (row - 2))
				p->setYpos(p->getYpos() + 1);
			break;
		case ' ':
			p->shoot(champBullets);
			if (p->getLevel() > 1 && p->getLevel() < 5)
				p->setScore(p->getScore() - 1);
			break;
		case 'q':
			return (false);
		default:
			break;
	}

	if (p->getLostLife()) {
		explode[0].setDCh((char *)"FUCK");
		explode[1].setDCh((char *)"FUCK_FUCK");
		explode[2].setDCh((char *)"FUCK_FUCK");
		explode[3].setDCh((char *)"FUCK");
		explode[0].setXpos(p->getXpos() + 3);
		explode[1].setXpos(p->getXpos() + 1);
		explode[2].setXpos(p->getXpos() + 1);
		explode[3].setXpos(p->getXpos() + 3);
		explode[0].setYpos(p->getYpos() + 1);
		explode[1].setYpos(p->getYpos());
		explode[2].setYpos(p->getYpos() - 1);
		explode[3].setYpos(p->getYpos() - 2);
		p->setLostLife(false);
	}

	for (int i = 0; i < 4; i++){
		explode[i].setXpos(explode[i].getXpos() - 1);
	}

	if (starcount % 2 == 0) {
		for (int i = 0; i < 30; i++) {
			stars[i].setXpos(stars[i].getXpos() - 1);
			if (stars[i].getXpos() == 0) {
				stars[i].setXpos(col - 1);
				stars[i].setYpos((rand() % (row - 2)) + 1);
			}
		}
		if (starcount % 4 == 0) {
			for (int i = 31; i < 60; i++) {
				stars[i].setXpos(stars[i].getXpos() - 1);
				if (stars[i].getXpos() == 0) {
					stars[i].setXpos(col - 1);
					stars[i].setYpos((rand() % (row - 2)) + 1);
				}
			}
			if (starcount % 8 == 0) {
				for (int i = 61; i < 90; i++) {
					stars[i].setXpos(stars[i].getXpos() - 1);
					if (stars[i].getXpos() == 0) {
						stars[i].setXpos(col - 1);
						stars[i].setYpos((rand() % (row - 2)) + 1);
					}
				}
				if (starcount % 16 == 0) {
					for (int i = 91; i < 120; i++) {
						stars[i].setXpos(stars[i].getXpos() - 1);
						if (stars[i].getXpos() == 0) {
							stars[i].setXpos(col - 1);
							stars[i].setYpos((rand() % (row - 2)) + 1);
						}
					}
				}
			}
		}
	}
	starcount++;
	for (int i = 0; i < 200; i++) {
		if (!enemyBullets[i].isCollided()) {
			enemyBullets[i].setXpos(enemyBullets[i].getXpos() - 3);
		}
	}
	int	isMove = 0;
	int	shoot_enemy = 0;
	for (int i = 0; i < 20; i++) {
		if (!s[i].isCollided()) {
			s[i].setXpos(s[i].getXpos() - 1);
			isMove = rand() % 10;
			if (p->getLevel() > 3 && isMove >= 8) {
				int set = s[i].getYpos() + rand() % 3 - 1;
				if (set < 1)
					set = 1;
				if (set > row - 2)
					set = row - 2;
				s[i].setYpos(set);
			}
			shoot_enemy = rand() % 10;
			if (shoot_enemy == 3 && p->getLevel() > 4)
				s[i].shoot(enemyBullets);
		}
		else if (s[i].getRespawnTime() > 0)
			s[i].setRespawnTime(s[i].getRespawnTime() - 1);
		else if (s[i].getRespawnTime() == 0)
			s[i].setCollided(false);
	}
	for (int i = 0; i < 10; i++) {
		if (!champBullets[i].isCollided())
			champBullets[i].setXpos(champBullets[i].getXpos() + 3);
	}
	checkCollision(p, s, champBullets, enemyBullets);
	return (true);
}
