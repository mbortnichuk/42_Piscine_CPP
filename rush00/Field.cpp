/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:28:21 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 16:28:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Field.hpp"

Field::Field() {
	initscr();
	raw();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	getmaxyx(stdscr, xMax, yMax);
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	time = clock();
}

Field::~Field() {
}

Field::Field(Field const & obj) {
	*this = obj;
}

int Field::getXmax()const {return xMax;}

int Field::getYmax()const {return yMax;}

void Field::setXmax(int xMax) {Field::xMax = xMax;}

void Field::setYmax(int yMax) {Field::yMax = yMax;}

Field &Field::operator=(Field const & obj) {
	setXmax(obj.getXmax());
	setYmax(obj.getYmax());

	return *this;
}

void Field::sleep(unsigned long int sleep) {
	clock_t start = clock();
	while (clock() - start < sleep) {
	}
}

void Field::printSummary(Champ *c) {
	static clock_t last = clock();
	clock_t current = clock_t();

	if (last / CLOCKS_PER_SEC != current / CLOCKS_PER_SEC) {
		last = current;
	}
	attron(COLOR_PAIR(7));
	mvprintw(1, 0, "*************************");
	mvprintw(2, 0, "*	Lives: %5d	*", c->getLive());
	mvprintw(3, 0, "*	Time : %5d	*", ((clock() - time) / CLOCKS_PER_SEC));
	mvprintw(4, 0, "*	Score: %5d	*", c->getScore());
	mvprintw(5, 0, "*	Level: %5d	*", c->getLevel());
	mvprintw(6, 0, "*************************");
	attron(COLOR_PAIR(3));
}

bool Field::endGame(int score) {
	int rowMax;
	int columnMax;
	char fail[] = "YOU FAIL! YOUR SCORE: ";
	char start[] = "'S' for <start> ";
	char quit[] = "'Q' to quit";
	char ch;

	clear();
	getmaxyx(stdscr, rowMax, columnMax);
	printBorders();
	attron(COLOR_PAIR(1));
	mvprintw(rowMax / 2, (rowMax) / 2, "%s%d", fail, score);
	attron(COLOR_PAIR(2));
	mvprintw((rowMax / 2), (columnMax) / 2, "%s", start);
	attron(COLOR_PAIR(1));
	mvprintw((rowMax / 2), (columnMax) / 2 + 20, "%s", quit);
	attron(COLOR_PAIR(3));
	for(;;) {
		ch = getch();
		if (ch == 'q' || ch == 'Q') {
			refresh();
			return (false);
		} else if (ch == 'S' || ch == 's')
		return true;
	}
}

bool Field::menu() {
	int rowMax;
	int columnMax;
	char startMessage[] = "Welcome to Spaceship War!";
	char instruction[] = "'S' for <start> 'Q' to quit";
	int ch;
	refresh();
	getmaxyx(stdscr, rowMax, columnMax);
	printBorders();
	attron(COLOR_PAIR(1));
	mvprintw(rowMax / 2, (rowMax - strlen(startMessage)) / 2, "%s", startMessage);
	attron(COLOR_PAIR(2));
	mvprintw((rowMax / 2), (columnMax - strlen(instruction)) / 2, "%s", instruction);
	attron(COLOR_PAIR(3));
	for (;;) {
		ch = getch();
		if (ch == 's')
			return true;
		if (ch == 'q')
			return false;
	}
}

void Field::updateScreen(Champ *c, SpaceShip s[], GameCore stars[], GameCore champBullets[], GameCore enemyBullets[], GameCore explode[]) {
	erase();
	static int fl = 0;
	if (fl % 9 != 0) {
		fl++;

		attron(COLOR_PAIR(1));
		for (int i = 0; i < 4; i++) {
			if ((std::string)explode[i].getDCh() != ".")
				mvprintw(explode[i].getYpos(), explode[i].getXpos(), explode[i].getDCh());
		}
		attron(COLOR_PAIR(3));
	} else {
		fl++;
	}
	for (int i = 0; i < 150; i++) {
		mvprintw(stars[i].getYpos(), stars[i].getXpos(), stars[i].getDCh());
	}
	attron(COLOR_PAIR(4));	
	mvprintw(c->getYpos(), c->getXpos(), c->getDCh());
	attron(COLOR_PAIR(3));
	for (int i = 0; i < 20; i++) {
		if (!s[i].isCollided()) {
			attron(COLOR_PAIR(6));
			mvprintw(s[i].getYpos(), s[i].getXpos(), s[i].getDCh());
			attron(COLOR_PAIR(3));
		}
	}
	for (int i = 0; i < 10; i++) {
		if (!(champBullets[i].isCollided())) {
			attron(COLOR_PAIR(5));
			mvprintw(champBullets[i].getYpos(), champBullets[i].getXpos(), champBullets[i].getDCh());
			attron(COLOR_PAIR(6));
			mvprintw(champBullets[i].getYpos(), champBullets[i].getXpos(), "*");
			attron(COLOR_PAIR(3));
		}
	}
	for (int i = 0; i < 200; i++) {
		if (!(enemyBullets[i].isCollided())) {
			attron(COLOR_PAIR(5));
			mvprintw(enemyBullets[i].getYpos(), enemyBullets[i].getXpos(), enemyBullets[i].getDCh());
			attron(COLOR_PAIR(6));
			mvprintw(enemyBullets[i].getYpos(), enemyBullets[i].getXpos(), "*");
			attron(COLOR_PAIR(3));
		}
	}
	printSummary(c);
	printBorders();
	refresh();
}

void Field::printBorders() {
	int rowMax;
	int columnMax;
	int i;
	getmaxyx(stdscr, rowMax, columnMax);
	attron(COLOR_PAIR(7));
	for (i = 0; i < columnMax; i++) {
		mvaddch(0, i, '|');
		mvaddch(rowMax - 1, i, '|');
	}
	for (i = 0; i < rowMax; i++) {
		mvaddch(0, i, '|');
		mvaddch(columnMax - 1, i, '|');
	}
	attron(COLOR_PAIR(3));
}

void Field::loadField() {
	int rowMax;
	int columnMax;
	int rowBlock;
	int columnBlock;
	bool load;

	getmaxyx(stdscr, rowMax, columnMax);
	printBorders();
	columnBlock = 1;
	rowBlock = 1;
	load = true;
	while (load) {
		if (columnBlock == columnMax - 1)
			columnBlock = 1;
		if (rowBlock == rowMax - 1)
			rowBlock = 1;
		attron(COLOR_PAIR(7));
		mvaddch(rowBlock, columnBlock, '#');
		attron(COLOR_PAIR(3));
		refresh();
		if (columnBlock == columnMax - 2 && rowBlock == rowMax - 2)
			load = false;
		columnBlock++;
		rowBlock++;
		sleep(10);
	}
	refresh();
	sleep(500000);
}
