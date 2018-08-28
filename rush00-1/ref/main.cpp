/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:59:15 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 11:59:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <numeric>
#include "Main.hpp"

int		hight_score = 0;

int		difficultyMode(int i) {
	if (i == 0)
		return 30;
	else if (i == 1)
		return 100;
	else
		return 300;
}

void	printDead(Playground & pl, Champ ch) {
	(void)ch;
	start_color();
	init_pair(6 ,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(6));

	mvprintw(pl.getY() / 3 + pl.getY() / 12, pl.getX() / 3 + pl.getX() / 16, " _____________________ ");
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 1, pl.getX() / 3 + pl.getX() / 16, "| SORRY, YOU ARE DEAD |");
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 2, pl.getX() / 3 + pl.getX() / 16, "|_____________________|");

	start_color();
	init_pair(19, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 19, pl.getX() / 3 + pl.getX() / 7 - 8, "    _____________    ");
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 20, pl.getX() / 3 + pl.getX() / 7 - 8, "   |  SCORE :    |   ");
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 21, pl.getX() / 3 + pl.getX() / 7 - 8, "   |_____________|   ");
	std::string		str;
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 20, pl.getX() / 3 + pl.getX() / 7, str.c_str());
	attroff(COLOR_PAIR(19));

	refresh();
	attroff(COLOR_PAIR(6));
	sleep(2);
}

void	game(int i, Playground& pl) {
	nodelay(stdscr, TRUE);
	i = difficultyMode(i);
	Champ		champ(pl);
	Enemy enemy = Enemy(i, "[-*-]");
	Jet jet = Jet(10, "*");
	Bullet bullet = Bullet(2, "[]");
	enemy.randomBoom(pl);
	int	inp = 0;
	champ.setZeroScore();
	while (inp != KEY_ESC && champ.getHP() > 0) {
		clear();
		jet.printScore(pl);
		pl.takeWindSize();
		pl.printBorder();
		inp = getch();
		jet.start(champ.getX(), champ.getY(), inp);
		bullet.start(champ.getX(), champ.getY(), inp);
		jet.checkDamage(enemy.getHorde(), enemy.getNum(), pl);
		bullet.checkDamage(enemy.getHorde(), enemy.getNum(), pl);
		champ.checkEnemies(enemy.getHorde(), enemy.getNum(), pl);
		champ.printLives(pl);
		jet.printCharge(pl);
		bullet.printCharge(pl);
		if (champ.getHP() > 0) {
			enemy.printIt(pl);
			jet.move(pl);
			bullet.move(pl);
			jet.printIt(pl);
			bullet.printIt(pl);
			champ.printIt(pl);
			champ.inputDirection(inp);
			wrefresh(pl.getWindow());
			champ.move(pl);
			champ.printIt(pl);
			enemy.move(pl);
		}
		while(getch() != ERR);
		usleep(60000);
	}
	if (champ.getHP() <= 0) {
		clear();
		printDead(pl, champ);
	}
	if (champ.getScore() > hight_score)
		hight_score = champ.getScore();

}

void	printLogo(Playground pl) {
	start_color();
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(pl.getY() / 8 + 7, pl.getX() / 2 - (pl.getX() / 3), " ____________________________________");
	mvprintw(pl.getY() / 8 + 8, pl.getX() / 2 - (pl.getX() / 3), "|           SPACE INVADERS           |");
	mvprintw(pl.getY() / 8 + 9, pl.getX() / 2 - (pl.getX() / 3), "|____________________________________|");
	attroff(COLOR_PAIR(1));
}

void		printScore(Playground & pl) {
	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvwprintw(pl.getWindow(), 1, 2, " _____________________ " );
	mvwprintw(pl.getWindow(), 2, 2, "| HIGHT SCORE :       |" );
	mvwprintw(pl.getWindow(), 3, 2, "|_____________________|" );
	std::string		str;
	mvwprintw(pl.getWindow(), 1, 16, str.c_str());
	attroff(COLOR_PAIR(19));
	refresh();
}

void	printMenu(Playground & pl) {
	int inp = 0;
	int i = 0;

	while (getch() != ERR);
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_RED);
	while(inp != KEY_ESC) {
		nodelay(stdscr, FALSE);
		clear();
		printLogo(pl);
		attron(COLOR_PAIR(2));
		if (i == 0) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 8, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 9, pl.getX() / 2 - (pl.getX() / 5), "| EASY |");
			mvprintw(pl.getY() / 4 + 10, pl.getX() / 2 - (pl.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 8, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 9, pl.getX() / 2 - (pl.getX() / 5), "| EASY |");
			mvprintw(pl.getY() / 4 + 10, pl.getX() / 2 - (pl.getX() / 5), "|______|");
		}
		
		if (i == 1) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 15, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 16, pl.getX() / 2 - (pl.getX() / 5), "| NORM |");
			mvprintw(pl.getY() / 4 + 17, pl.getX() / 2 - (pl.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 15, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 16, pl.getX() / 2 - (pl.getX() / 5), "| NORM |");
			mvprintw(pl.getY() / 4 + 17, pl.getX() / 2 - (pl.getX() / 5), "|______|");
		}
		
		if (i == 2) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 22, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 23, pl.getX() / 2 - (pl.getX() / 5), "| HARD |");
			mvprintw(pl.getY() / 4 + 24, pl.getX() / 2 - (pl.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 22, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 23, pl.getX() / 2 - (pl.getX() / 5), "| HARD |");
			mvprintw(pl.getY() / 4 + 24, pl.getX() / 2 - (pl.getX() / 5), "|______|");
		}
		
		if (i == 3) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 29, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 30, pl.getX() / 2 - (pl.getX() / 5), "| EXIT |");
			mvprintw(pl.getY() / 4 + 31, pl.getX() / 2 - (pl.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 29, pl.getX() / 2 - (pl.getX() / 5), " ______ ");
			mvprintw(pl.getY() / 4 + 30, pl.getX() / 2 - (pl.getX() / 5), "| EXIT |");
			mvprintw(pl.getY() / 4 + 31, pl.getX() / 2 - (pl.getX() / 5), "|______|");
		}
		printScore(pl);
		attroff(COLOR_PAIR(2));

		inp = getch();
		if (inp == 259) {
			i--;
			if (i == -1)
				i = 3;
		} else if (inp == 258) {
			i++;
			if (i == 4)
				i = 0;
		} else if (inp == 10) {
			if (i >= 0 && i < 3)
				game(i, pl);
			else
				return;
		}
		refresh();
	}
}

void	menu(void) {
	srand(time(NULL));
	Playground pl;
	clear();
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printScore(pl);
	printLogo(pl);
	printMenu(pl);
	attroff(COLOR_PAIR(1));
	refresh();
}

int main(void) {
	menu();
}
