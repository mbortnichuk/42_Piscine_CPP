/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jet.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:04:00 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:04:02 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Jet.hpp"

Jet::Jet(int N, std::string form) {
	m_max = N;
	m_index = 0;
	m_Jets = new Jet[N]();
	for (int i = 0; i < N; i++) {
		m_Jets[i].setForm(form);
		m_Jets[i].setDir(0, -1);
		m_Jets[i].setHP(0);
	}
}

Jet::Jet(void):Object() {
	m_max = 0;
	m_index = 0;
	m_Jets = NULL;
	m_hp = 0;
	return;
}


Jet::Jet(Jet const & src):Object(src) {
	*this = src;
	return;
}

Jet::~Jet(void) {
	if (m_Jets) {
		delete [] m_Jets;
		m_Jets = NULL;
	}
	return;
}

Jet* Jet::getJet(void)const { return (m_Jets); }

int	Jet::getIndex(void)const { return (m_index); }

int	Jet::getMax(void)const { return (m_max); }

int	Jet::check_m_dispo(void) {
	int		i = 0;
	while (i < m_max) {
		if (m_Jets[i].getHP() == 0)
			return i;
		i++;
	}
	return -1;
}

void Jet::activate(int xpos, int ypos, int input) {
	int		i = check_m_dispo();
	if (input == 32 && i >= 0) {
		m_Jets[i].setPos(xpos + 1, ypos - 1);
		m_Jets[i].setHP(1);
	}
}

void Jet::checkDamages(Enemy* horde, int Nu, Playground& win) {
	int center;
	int centerv;
	for (int i = 0; i < m_max; i++) {
		for (int e = 0; e < Nu; e++) {
			if (m_Jets[i].getHP() > 0 && horde[e].getHP() > 0) {
				if (abs(m_Jets[i].getY() - horde[e].getY()) <= 3) {
					center = horde[e].getX() + (horde[e].getsizeX() / 3);
					centerv = m_Jets[i].getX();
					centerv -= center;
					if (abs(centerv) <= 2) {
						m_Jets[i].colision(horde[e]);
						m_Jets[i].explode(win, 1);
						horde[e].die(win);
						m_Jets[i].setHP(0);
					}
				}
			}
		}
	}
}

void Jet::printit(Playground& win)const {
	start_color();
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	attron(COLOR_PAIR(7));
	for (int i = 0; i < m_max; i++)
		m_Jets[i].Object::printit(win);
	attroff(COLOR_PAIR(7));
}

void Jet::move(Playground& win) {
	for (int i = 0; i < m_max; i++) {
		if (m_Jets[i].getY() < 0) {
			m_Jets[i].setHP(0);
		}
		m_Jets[i].Object::move(win);
	}
}

Jet& Jet::operator=(Jet const & rhs) {
	Object::operator=(rhs);
	return (*this);
}

void Jet::print_chargeur(Playground & win) {
	int i = 0;
	int mun = 0;

	while (i < m_max) {
		if (m_Jets[i].getHP() == 0)
			mun++;
		i++;
	}
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));

	mvwprintw(win.getWin(), win.getY() - 22 + i , win.getX() - 38 , "             _________ ");
	mvwprintw(win.getWin(), win.getY() - 21 + i , win.getX() - 38 , "            | AMMO  * |");
	mvwprintw(win.getWin(), win.getY() - 20 + i , win.getX() - 38 , "            |_________|");

	// mvwprintw(win.getWin(), win.getY() - 16 + i , win.getX() - 46 , "   ___   __  _____  _______ ");
	// mvwprintw(win.getWin(), win.getY() - 15 + i , win.getX() - 46 , "  / _ | /  |/  /  |/  / __ \\ []");
	// mvwprintw(win.getWin(), win.getY() - 14 + i , win.getX() - 46 , " / __ |/ /|_/ / /|_/ / /_/ /");
	// mvwprintw(win.getWin(), win.getY() - 13 + i , win.getX() - 46 , "/_/ |_/_/  /_/_/  /_/\\____/  []");
	attroff(COLOR_PAIR(18));

	if (mun > m_max - (m_max / 3))
		attron(COLOR_PAIR(5));
	else if (mun > m_max - (2 * m_max / 3))
		attron(COLOR_PAIR(7));
	else
		attron(COLOR_PAIR(6));

	for (i = 1; i < m_max + 1; i++)
		if ( i == m_max)
			mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 14 , "|____________");
		else
			mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 14 , "| ");
	
	for (i = 1; i < m_max + 1; i++)
		mvwprintw(win.getWin(), win.getY() - 12 + i , win.getX() - 2 , "| ");

	while ( mun > 0) {
		mvwprintw(win.getWin(), win.getY() - m_max - 1 -  (mun - m_max) , win.getX() - 12, "@@@@@@@@@");
		mun--;
	}
	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
}
