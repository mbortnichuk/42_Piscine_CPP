/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Champ.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:02:34 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 16:02:35 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Champ.hpp"

Champ::Champ() {
	dCh = (char*)"<{|]*[|}-->";
	score = 0;
	lives = 1;
	xpos = 10;
	ypos = 10;
	collided = false;
	lostLife = false;
	level = 1;
}

Champ::Champ(char *s) {
	dCh = s;
	score = 0;
	lives = 1;
	xpos = 10;
	ypos = 10;
	collided = false;
	lostLife = false;
	level = 1;
}

Champ::Champ(const Champ & obj) {
	*this = obj;
}

Champ &Champ::operator=(Champ const & obj) {
	setDCh(obj.getDCh());
	setXpos(obj.getXpos());
	setYpos(obj.getYpos());
	setLive(obj.getLive());
	setScore(obj.getScore());

	return *this;
}

Champ::~Champ() {
}

void Champ::collide() {
	int x;
	int y;
	getmaxyx(stdscr, y, x);
	lives--;
	lostLife--;
	if (lives == 0)
		setCollided(true);
}

int Champ::getScore()const {return score;}

int Champ::getLive()const {return lives;}

int Champ::getLostLife()const {return lostLife;}

int	Champ::getLevel()const {return level;}


void Champ::setScore(int score) {Champ::score = score;}

void Champ::setLive(int lives) {Champ::lives = lives;}

void Champ::setLostLife(int lostLife) {Champ::lostLife = lostLife;}

void Champ::setLevel(int score) {
	if (level == 1 && score >= 50) {
		system("afplay levelUp.mp3 &");
		lives++;
		level++;
	}
	if (level == 2 && score >= 100) {
		system("afplay levelUp.mp3 &");
		lives++;
		level++;
	}
	if (level == 3 && score >= 150) {
		system("afplay levelUp.mp3 &");
		lives += 2;
		level++;
	}
	if (level == 4 && score >= 200) {
		system("afplay levelUp.mp3 &");
		lives += 2;
		level++;
	}
}
