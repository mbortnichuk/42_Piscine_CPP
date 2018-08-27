/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Champ.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:05:55 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:05:56 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Champ.hpp"
#include <iostream>

Champ::Champ(void):Object() { return; }

Champ::Champ(Playground& pl):Object((pl.getX() / 2), (pl.getY() - 5), 0, 0, 1, 3, "//*\\\\") { return; }

Champ::Champ(Champ const & src):Object(src) {
	*this = src;
	return;
}

Champ::~Champ(void) { return; }

void				Champ::printIt(Playground& pl)const {
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(5));
	if (m_posx >= 0 && m_posx <= pl.getX() && m_posy > 0 && m_posy < pl.getY() && m_hp > 0)
		mvwprintw(pl.getWin(), m_posy, m_posx, m_form.data());
	attroff(COLOR_PAIR(5));
}


void Champ::inputDirection(int ch) {
	this->input = 1;
	if (ch == 259 || ch == 258)
		ch == 258 ? m_diry += 1 : m_diry -= 1;
	else if (ch == 260 || ch == 261)
		ch == 261 ?  m_dirx += 2 : m_dirx -= 2;
	if (m_dirx < -2)
		m_dirx = -2;
	if (m_dirx > 2)
		m_dirx = 2;
	if (m_diry < -1)
		m_diry = -1;
	if (m_diry > 1)
		m_diry = 1;
}

void Champ::move(Playground& pl) {
	this->input = !this->input;
	m_posy += (m_diry * m_speed);
	m_posx += (m_dirx * m_speed);
	if (m_posy <= 0)
		m_posy = 1;
	if (m_posy >= pl.getY() - 1)
		m_posy = pl.getY() - 1;
	if (m_posx <= 0)
		m_posx = 1;
	if (m_posx >= pl.getX() - 1)
		m_posx = pl.getX() - 2;
	if (this->input)
	 	this->setDir(0, 0);
}

void		Champ::printLives(Playground & pl)const {
	start_color();
	init_pair(5,COLOR_GREEN,COLOR_BLACK);
	init_pair(6,COLOR_RED,COLOR_BLACK);
	init_pair(7,COLOR_YELLOW,COLOR_BLACK);
	init_pair(18,COLOR_WHITE,COLOR_BLACK);
	attron(COLOR_PAIR(18));

	mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 1, pl.getX() - 40 , "                _________ ");
	mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 2, pl.getX() - 40 , "               | LIFE :  |");
	mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 3 , pl.getX() - 40 , "               |_________|");
	attroff(COLOR_PAIR(18));
	if (m_hp == 3) {
		attron(COLOR_PAIR(5));

		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , "   _____ ");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "  |  3  |");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , "  |_____|");
		attroff(COLOR_PAIR(5));
	} else if (m_hp == 2) {
		attron(COLOR_PAIR(7));
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , "   _____ ");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "  |  2  |");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , "  |_____|");
		attroff(COLOR_PAIR(7));
	} else {	attron(COLOR_PAIR(6));
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 1 , pl.getX() - 10 , "   _____ ");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 2 , pl.getX() - 10 , "  |  1  |");
		mvwprintw(pl.getWin(), pl.getY() - pl.getY() + 3 , pl.getX() - 10 , "  |_____|");
		attroff(COLOR_PAIR(6));
		//refresh();
	}
}

void Champ::checkEnemies(Enemy* horde, int N, Playground& pl) {
	int center;
	int centerv;
	for (int i = 0; i < N; i++) {
		if (horde[i].getY() == m_posy) {
			center = horde[i].getX() - (horde[i].getsizeX() / 2);
			centerv = m_posx - (m_sizex / 2);
			centerv -= center;
			if (abs(centerv) <= m_sizex) {
				m_hp -= 1;
				pl.setColor(2);
				pl.printBorder();
				horde[i].die(pl);
				pl.setColor(0);
			}
		}
	}
}

Champ& Champ::operator=(Champ const & rhs) {
	Object::operator=(rhs);
	return (*this);
}
