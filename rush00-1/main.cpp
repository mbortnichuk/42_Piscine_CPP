/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:31:18 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/17 17:31:19 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <numeric>
#include "Main.hpp"

int highScore = 0;

void printScore(Playground & pl) {
	start_color();
	init_pair(19, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvwprintw(pl.getWindow(), 1, 2, "HIGH SCORE: ");
	std::string line;
	mvwprintw(pl.getWindow(), 1, 16, line.c_str());
	attroff(COLOR_PAIR(19));
	refresh();
}

void printMenu(Playground & pl) {
	int inp = 0;
	int i = 0;

	while (getch() != ERR);
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_RED);

	while (inp != KEY_ESC) {
		nodelay(stdscr, FALSE);
		clear();
		printLogo(pl);
		attron(COLOR_PAIR(2));

		if (i == 0) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 9, pl.getX() / 2 - (pl.getX() / 5), "EASY");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 9, pl.getX() / 2 - (pl.getX() / 5), "EASY");
		}

		if (i == 1) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 16, pl.getX() / 2 - (pl.getX() / 5), "NORMAL");
		} else {
			mvprintw(pl.getY() / 4 + 16, pl.getX() / 2 - (pl.getX() / 5), "NORMAL");
		}

		if (i == 2) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 23, pl.getX() / 2 - (pl.getX() / 5), "HARD");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 23, pl.getX() / 2 - (pl.getX() / 5), "HARD");
		}

		if (i == 3) {
			attron(COLOR_PAIR(3));
			mvprintw(pl.getY() / 4 + 30, pl.getX() / 2 - (pl.getX() / 5), "EXIT");
			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(pl.getY() / 4 + 30, pl.getX() / 2 - (pl.getX() / 5), "EXIT");
		}

		printScore(pl);
		attroff(COLOR_PAIR(2));
		inp = getch();

		if (inp == 259) {
			i--;
			if (i == 4)
				i = 3;
		} else if (inp == 258) {
			i++;
			if (i == 4)
				i = 0;
		} else if (inp == 10) {
			if (i >= 0 && i < 3)
				getStarted(i, pl);
			else
				return ;
		}
		refresh();
	}
}

void printLogo(Playground pl) {
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(pl.getY() / 6, pl.getX() / 2 - (pl.getX() / 3) , "  _____ _____        _____ ______           _____ ____  _   _  ____  _    _ ______ _____   ____  _____ ");
	mvprintw(pl.getY() / 6 + 1, pl.getX() / 2 - (pl.getX() / 3), " / ____|  __ \\ /\\   / ____|  ____|         / ____/ __ \\| \\ | |/ __ \\| |  | |  ____|  __ \\ / __ \\|  __ \\ ");
	mvprintw(pl.getY() / 6 + 2,  pl.getX() / 2 - (pl.getX() / 3), "| (___ | |__) /  \\ | |    | |__           | |   | |  | |  \\| | |  | | |  | | |__  | |__) | |  | | |__) |");
	mvprintw(pl.getY() / 6 + 3,  pl.getX() / 2 - (pl.getX() / 3), " \\___ \\|  ___/ /\\ \\| |    |  __|          | |   | |  | | . ` | |  | | |  | |  __| |  _  /| |  | |  _  / ");
	mvprintw(pl.getY() / 6 + 4,  pl.getX() / 2 - (pl.getX() / 3), " ____) | |  / ____ \\ |____| |____         | |___| |__| | |\\  | |__| | |__| | |____| | \\ \\| |__| | | \\ \\ ");
	mvprintw(pl.getY() / 6 + 5, pl.getX() / 2 - (pl.getX() / 3) , "|_____/|_| /_/    \\_\\_____|______|         \\_____\\____/|_| \\_|\\___\\_\\_____/|______|_|  \\_\\_____/|_|  \\_\\ ");
	attroff(COLOR_PAIR(1));
}

void printDie(Playground & pl, Champ ch) {
	(void)ch;
	start_color();
	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	mvprintw( pl.getY() / 3 + pl.getY() / 12 , pl.getX() / 3 + pl.getX() / 16, "RRRRRRRRRRRRRRRRR           IIIIIIIIII        PPPPPPPPPPPPPPPPP   ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 1 , pl.getX() / 3 + pl.getX() / 16, "R::::::::::::::::R          I::::::::I        P::::::::::::::::P  ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 2, pl.getX() / 3 + pl.getX() / 16, "R::::::RRRRRR:::::R         I::::::::I        P::::::PPPPPP:::::P");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 3, pl.getX() / 3 + pl.getX() / 16, "RR:::::R     R:::::R        II::::::II        PP:::::P     P:::::P");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 4 , pl.getX() / 3 + pl.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P     P:::::P");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 5, pl.getX() / 3 + pl.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P     P:::::P");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 6, pl.getX() / 3 + pl.getX() / 16, "  R::::RRRRRR:::::R           I::::I            P::::PPPPPP:::::P ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 7, pl.getX() / 3 + pl.getX() / 16, "  R:::::::::::::RR            I::::I            P:::::::::::::PP  ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 8 , pl.getX() / 3 + pl.getX() / 16, "  R::::RRRRRR:::::R           I::::I            P::::PPPPPPPPP    ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 9, pl.getX() / 3 + pl.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 10, pl.getX() / 3 + pl.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 11, pl.getX() / 3 + pl.getX() / 16, "  R::::R     R:::::R          I::::I            P::::P            ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 12, pl.getX() / 3 + pl.getX() / 16, "RR:::::R     R:::::R        II::::::II        PP::::::PP          ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 13, pl.getX() / 3 + pl.getX() / 16, "R::::::R     R:::::R ...... I::::::::I ...... P::::::::P          ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 14, pl.getX() / 3 + pl.getX() / 16, "R::::::R     R:::::R .::::. I::::::::I .::::. P::::::::P          ");
	mvprintw( pl.getY() / 3 + pl.getY() / 12 + 15, pl.getX() / 3 + pl.getX() / 16, "RRRRRRRR     RRRRRRR ...... IIIIIIIIII ...... PPPPPPPPPP          ");
	start_color();
	init_pair(19, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 20, pl.getX() / 3 + pl.getX() / 7 - 8, "SCORE: ");
	std::string line;
	mvprintw(pl.getY() / 3 + pl.getY() / 12 + 20, pl.getX() / 3 + pl.getX() / 7, line.c_str());
	attroff(COLOR_PAIR(19));
	refresh();
	attroff(COLOR_PAIR(6));
	sleep(2);
}

int difficultyMode(int i) {
	if (i == 0)
		return 30;
	else if (i == 1)
		return 100;
	else
		return 3000;
}

void getStarted(int i, Playground & pl) {
	nodelay(stdscr, TRUE);
	i = difficultyMode(i);
	Champ ch(pl);
	Enemy enemy = Enemy(i, "[-*-]");
	Jet jet = Jet(10, "*");
	Bullet bull = Bullet(2, "[]");
	enemy.randomBoom(pl);
	int inp = 0;
	ch.setZeroScore();

	while (inp != KEY_ESC && ch.getHP() > 0) {
		clear();
		jet.printScore(pl);
		pl.takeWindSize();
		pl.printBorder();
		inp = getch();
		jet.start(ch.getX(), ch.getY(), inp);
		bull.start(ch.getX(), ch.getY(), inp);
		jet.checkDamage(enemy.getHorde(), enemy.getNum(), pl);
		bull.checkDamage(enemy.getHorde(), enemy.getNum(), pl);
		ch.printLives(pl);
		jet.printCharge(pl);
		bull.printCharge(pl);

		if (ch.getHP() > 0) {
			enemy.printIt(pl);
			jet.move(pl);
			bull.move(pl);
			jet.printIt(pl);
			bull.printIt(pl);
			ch.printIt(pl);
			ch.inputDir(inp);
			wrefresh(pl.getWindow());
			ch.move(pl);
			ch.printIt(pl);
			enemy.move(pl);
		}

		while (getch() != ERR);
		usleep(60000);
	}

	if (ch.getHP() <= 0) {
		clear();
		printDie(pl, ch);
	}
	if (ch.getScore() > highScore)
		highScore = ch.getScore();
}

void game(void) {
	srand(time(0));
	Playground pl;
	clear();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	printScore(pl);
	printLogo(pl);
	printMenu(pl);
	attroff(COLOR_PAIR(1));
	refresh();
}

int main(void) {
	game();
}
