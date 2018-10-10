/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:18:13 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:18:14 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interface.class.hpp"

Interface::Interface(void):y(0), mod(0) { return; }

Interface::~Interface(void) {
	endwin();
	return;
}

void Interface::init(void) {
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_WHITE);
	init_pair(8, COLOR_BLUE, COLOR_BLUE);
	init_pair(9, COLOR_RED, COLOR_RED);
	init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(11, COLOR_GREEN, COLOR_GREEN);
	init_color(12, 300, 300, 300);
	init_pair(13, 12, COLOR_BLACK);
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

int Interface::getKey(CPUModule const & cpu, HostnameModule const & hostname, TimeModule const & time, NetworkModule const & net, RAMModule const & ram, OSInfoModule const & os) {
	int key = 0;

	switch ((key = getch())) {
		case ONE:
		if (!(this->mod & (1 << 1))) {
			this->mod |= 1 << 1;
			this->pos[0] = this->y;
			this->y += cpu.getHeight();
		}
		break;
		case TWO:
		if (!(this->mod & (1 << 2))) {
			this->mod |= 1 << 2;
			this->pos[1] = this->y;
			this->y += hostname.getHeight();
		}
		break;
		case THR:
		if (!(this->mod & (1 << 3))) {
			this->mod |= 1 << 3;
			this->pos[2] = this->y;
			this->y += time.getHeight();
		}
		break;
		case FOR:
		if (!(this->mod & (1 << 4))) {
			this->mod |= 1 << 4;
			this->pos[3] = this->y;
			this->y += net.getHeight();
		}
		break;
		case FIV:
		if (!(this->mod & (1 << 5))) {
			this->mod |= 1 << 5;
			this->pos[4] = this->y;
			this->y += ram.getHeight();
		}
		break;
		case SIX:
		if (!(this->mod & (1 << 6))) {
			this->mod |= 1 << 6;
			this->pos[5] = this->y;
			this->y += os.getHeight();
		}
		break;
	}
	return (key);
}

void Interface::start(void) {
	int key;
	CPUModule cpu;
	RAMModule ram;
	HostnameModule host;
	TimeModule time;
	NetworkModule net;
	OSInfoModule os;

	initscr();
	this->init();
	while ((key = this->getKey(cpu, host, time, net, ram, os)) != ESC) {
		if (COLS != 30 || LINES != 45)
			system("printf '\e[8;29;41t'");
		erase();
		
		if (this->mod & (1 << 1))
			cpu.show(this->pos[0]);
		if (this->mod & (1 << 2))
			host.show(this->pos[1]);
		if (this->mod & (1 << 3))
			time.show(this->pos[2]);
		if (this->mod & (1 << 4))
			net.show(this->pos[3]);
		if (this->mod & (1 << 5))
			ram.show(this->pos[4]);
		if (this->mod & (1 << 6))
			os.show(this->pos[5]);

		wrefresh(stdscr);
		sleep(1);
	}
}
