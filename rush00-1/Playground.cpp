/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Playground.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:46:15 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/17 17:46:16 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"
#include "Playground.hpp"

Playground::Playground(void): _clr(0) {
	initscr();
	minWin = stdscr;
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(minWin, minSizeY, minSizeX);
	nodelay(stdscr, TRUE);
	if (has_colors() == FALSE) {
		endwin();
		std::cout << "This color are not available in this terminal version." << std::endl;
		exit(1);
	}
	return ;
}

Playground::Playground(Playground const & src) {
	*this = src;
	return ;
}

Playground::~Playground(void) {
	endwin();
	return;
}

void Playground::setClr(int i) {
	_clr = i;
}

int Playground::getX(void)const {
	return (minSizeX - 1);
}

int Playground::getY(void)const {
	return (minSizeY - 1);
}

WINDOW* Playground::getWindow(void)const {
	return (minWin);
}

void Playground::printBorder() {
	if (_clr == 1) {
		start_color();
		init_pair(12, COLOR_GREEN, COLOR_GREEN);
		attron(COLOR_PAIR(12));
	}
	if (_clr == 2) {
		start_color();
		init_pair(14, COLOR_RED, COLOR_RED);
		attron(COLOR_PAIR(14));
	}

	for (int i = 0; i < minSizeX; i++) {
		mvprintw(getX(), i, "-");
	}
	for (int i = 0; i < minSizeX; i++) {
		mvprintw(getY(), i, "-");
	}
	for (int i = 0; i < minSizeX; i++) {
		mvprintw(i, 0, "|");
	}
	for (int i = 0; i < minSizeX; i++) {
		mvprintw(i, getX(), "|");
	}
	attroff(COLOR_PAIR(14));
	attroff(COLOR_PAIR(12));
}

void Playground::takeWindSize(void) {
	getmaxyx(minWin, minSizeY, minSizeX);
	printBorder();
}

Playground& Playground::operator=(Playground const & rhs) {
	minSizeX = rhs.getX() + 1;
	minSizeY = rhs.getY() + 1;
	minWin = rhs.getWindow();

	return (*this);
}
