/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:11:52 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:11:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Champ.hpp"
#include "Actions.hpp"
#include "SpaceShip.hpp"
#include "Field.hpp"
#include "GameCore.hpp"
#include <ctime>

void	sleep(unsigned long int sleep) {
	clock_t start = clock();
	while (clock() - start < sleep) {
	}
}

int gameLoop() {
	Actions act;
	Champ *c = new Champ;
	SpaceShip s1[20];
	GameCore stars[150];
	GameCore champBullets[10];
	GameCore enemyBullets[200];
	GameCore explode[4];

	Field field;
	bool stillGameOn = true;
	int ch, score;

	timeout(0);
	c->initiateBullets(champBullets, 10, (char*)"*->");
	s1->initiateBullets(enemyBullets, 200, (char*)"<-*");
	while (stillGameOn) {
		ch = getch();
		act.setAction(ch);
		if (ch == 'p' || ch == 'P') {
			ch = 'e';
			while (ch != 'p' && ch != 'P')
				ch = getch();
		}
		stillGameOn = act.applyAct(c, s1, stars, champBullets, enemyBullets, explode);
		field.updateScreen(c, s1, stars, champBullets, enemyBullets, explode);
		if (c->isCollided() || c->getLive() == 0)
			stillGameOn = false;
		sleep(40000);
	}
	score = c->getScore();
	delete c;
	return (score);
}

int main(void) {
	srand(time(0));
	bool game = 1;
	int score;
	Field *field = new Field;
	field->loadField();

	system("afplay space.mp3 &");
	while (game == 1) {
		game = field->menu();
		if (game) {
			score = gameLoop();
			game = field->endGame(score);
		}
	}
	field->loadField();
	endwin();
	system("pkill afplay");
	delete field;
	return 0;
}
