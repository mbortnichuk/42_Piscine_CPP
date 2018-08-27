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

int		get_difficult(int i) {
	if (i == 0)
		return 30;
	else if (i == 1)
		return 100;
	else
		return 300;
}

void	print_die(Playground & win, Champ p) {
	(void)p;
	start_color();
	init_pair(6 ,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(6));

	mvprintw(win.getY() / 3 + win.getY() / 12, win.getX() / 3 + win.getX() / 16, " _____________________ ");
	mvprintw(win.getY() / 3 + win.getY() / 12 + 1, win.getX() / 3 + win.getX() / 16, "| SORRY, YOU ARE DEAD |");
	mvprintw(win.getY() / 3 + win.getY() / 12 + 2, win.getX() / 3 + win.getX() / 16, "|_____________________|");

	start_color();
	init_pair(19, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvprintw(win.getY() / 3 + win.getY() / 12 + 19, win.getX() / 3 + win.getX() / 7 - 8, "    _____________    ");
	mvprintw(win.getY() / 3 + win.getY() / 12 + 20, win.getX() / 3 + win.getX() / 7 - 8, "   |  SCORE :    |   ");
	mvprintw(win.getY() / 3 + win.getY() / 12 + 21, win.getX() / 3 + win.getX() / 7 - 8, "   |_____________|   ");
	std::string		str;
	mvprintw(win.getY() / 3 + win.getY() / 12 + 20, win.getX() / 3 + win.getX() / 7, str.c_str());
	attroff(COLOR_PAIR(19));

	refresh();
	attroff(COLOR_PAIR(6));
	sleep(2);
}

void	play(int i, Playground& win) {
	nodelay(stdscr, TRUE);
	i = get_difficult(i);
	Champ		p(win);
	Enemy n = Enemy(i, "[-*-]");
	Jet miss = Jet(10, "*");
	Bullet rock = Bullet(2, "[]");
	n.randomBoom(win);
	int	input = 0;
	p.setScoreZero();
	while (input != KEY_ESC && p.getHP() > 0) {
		clear();
		miss.print_score(win);
		win.takeSize();
		win.printBorder();
		input = getch();
		miss.activate(p.getX(), p.getY(), input);
		rock.start(p.getX(), p.getY(), input);
		miss.checkDamages(n.getHorde(), n.getNum(), win);
		rock.checkDamage(n.getHorde(), n.getNum(), win);
		p.checkEnemies(n.getHorde(), n.getNum(), win);
		p.printLives(win);
		miss.print_chargeur(win);
		rock.printCharge(win);
		if (p.getHP() > 0) {
			n.printit(win);
			miss.move(win);
			rock.move(win);
			miss.printit(win);
			rock.printIt(win);
			p.printIt(win);
			p.inputDirection(input);
			wrefresh(win.getWin());
			p.move(win);
			p.printIt(win);
			n.move(win);
		}
		while(getch() != ERR);
		usleep(60000);
	}
	if (p.getHP() <= 0) {
		clear();
		print_die(win, p);
	}
	if (p.getScore() > hight_score)
		hight_score = p.getScore();

}

void	print_logo(Playground win) {
	start_color();
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(win.getY() / 8 + 7, win.getX() / 2 - (win.getX() / 3), " ____________________________________");
	mvprintw(win.getY() / 8 + 8, win.getX() / 2 - (win.getX() / 3), "|           SPACE INVADERS           |");
	mvprintw(win.getY() / 8 + 9, win.getX() / 2 - (win.getX() / 3), "|____________________________________|");
	attroff(COLOR_PAIR(1));
}

void		print_score(Playground & win) {
	start_color();
	init_pair(19,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(19));
	mvwprintw(win.getWin(), 1, 2, " _____________________ " );
	mvwprintw(win.getWin(), 2, 2, "| HIGHT SCORE :       |" );
	mvwprintw(win.getWin(), 3, 2, "|_____________________|" );
	std::string		str;
	mvwprintw(win.getWin(), 1, 16, str.c_str());
	attroff(COLOR_PAIR(19));
	refresh();
}

void	print_menu(Playground & win) {
	int		input = 0;
	int		i = 0;

	while (getch() != ERR);
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_GREEN,COLOR_BLACK);
	init_pair(3,COLOR_GREEN,COLOR_RED);
	while(input != KEY_ESC) {
		nodelay(stdscr, FALSE);
		clear();
		print_logo(win);
		attron(COLOR_PAIR(2));
		if (i == 0) {
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 8, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 9, win.getX() / 2 - (win.getX() / 5), "| EASY |");
			mvprintw(win.getY() / 4 + 10, win.getX() / 2 - (win.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(win.getY() / 4 + 8, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 9, win.getX() / 2 - (win.getX() / 5), "| EASY |");
			mvprintw(win.getY() / 4 + 10, win.getX() / 2 - (win.getX() / 5), "|______|");
		}
		
		if (i == 1) {
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 15, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 16, win.getX() / 2 - (win.getX() / 5), "| NORM |");
			mvprintw(win.getY() / 4 + 17, win.getX() / 2 - (win.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(win.getY() / 4 + 15, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 16, win.getX() / 2 - (win.getX() / 5), "| NORM |");
			mvprintw(win.getY() / 4 + 17, win.getX() / 2 - (win.getX() / 5), "|______|");
		}
		
		if (i == 2) {
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 22, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 23, win.getX() / 2 - (win.getX() / 5), "| HARD |");
			mvprintw(win.getY() / 4 + 24, win.getX() / 2 - (win.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(win.getY() / 4 + 22, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 23, win.getX() / 2 - (win.getX() / 5), "| HARD |");
			mvprintw(win.getY() / 4 + 24, win.getX() / 2 - (win.getX() / 5), "|______|");
		}
		
		if (i == 3) {
			attron(COLOR_PAIR(3));
			mvprintw(win.getY() / 4 + 29, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 30, win.getX() / 2 - (win.getX() / 5), "| EXIT |");
			mvprintw(win.getY() / 4 + 31, win.getX() / 2 - (win.getX() / 5), "|______|");

			attroff(COLOR_PAIR(3));
			attron(COLOR_PAIR(2));
		} else {
			mvprintw(win.getY() / 4 + 29, win.getX() / 2 - (win.getX() / 5), " ______ ");
			mvprintw(win.getY() / 4 + 30, win.getX() / 2 - (win.getX() / 5), "| EXIT |");
			mvprintw(win.getY() / 4 + 31, win.getX() / 2 - (win.getX() / 5), "|______|");
		}
		print_score(win);
		attroff(COLOR_PAIR(2));

		input = getch();
		if (input == 259) {
			i--;
			if (i == -1)
				i = 3;
		} else if (input == 258) {
			i++;
			if (i == 4)
				i = 0;
		} else if (input == 10) {
			if (i >=0 && i < 3)
				play(i, win);
			else
				return;
		}
		refresh();
	}
}

void	menu(void) {
	srand(time(NULL));
	Playground win;
	clear();
	start_color();
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	init_pair(2,COLOR_RED,COLOR_BLACK);
	attron(COLOR_PAIR(1));
	print_score(win);
	print_logo(win);
	print_menu(win);
	attroff(COLOR_PAIR(1));
	refresh();
}

int main(void) {
	menu();
}

