/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Playground.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:29:46 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:29:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Main.hpp"

Playground::Playground(void):_color(0) {
	initscr();
	m_win = stdscr;
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	getmaxyx(m_win, m_sizey, m_sizex);
	nodelay(stdscr, TRUE);
	if (has_colors() == FALSE) {
		endwin();
		std::cout << "Color are not eneable in this term." << std::endl;
		exit(1);
	}
	return;
}

Playground::Playground(Playground const & src) {
	*this = src;
	return;
}

Playground::~Playground(void) {
	endwin();
	return;
}

void	Playground::setColor(int i) { _color = i; }

int 	Playground::getX(void)const { return(m_sizex - 1); }

int 	Playground::getY(void)const { return(m_sizey - 1); }

WINDOW* Playground::getWin(void)const { return(m_win); }

void	Playground::printBorder() {
	if (_color == 1) {
		start_color();
		init_pair(12,COLOR_GREEN,COLOR_GREEN);
		attron(COLOR_PAIR(12));
	}

	if (_color == 2) {
		start_color();
		init_pair(14,COLOR_RED,COLOR_RED);
		attron(COLOR_PAIR(14));
	}

	for (int i = 0; i < m_sizex; i++)
		mvprintw(getX(), i, "-");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(getY(), i, "-");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, 0, "|");
	for (int i = 0; i < m_sizex; i++)
		mvprintw(i, getX(), "|");
	attroff(COLOR_PAIR(14));
	attroff(COLOR_PAIR(12));
}

void 	Playground::takeSize(void) {
	getmaxyx(m_win, m_sizey, m_sizex);
	printBorder();
}

Playground& Playground::operator=(Playground const & rhs) {
	m_sizex = rhs.getX() + 1;
	m_sizey = rhs.getY() + 1;
	m_win = rhs.getWin();
	return (*this);
}

