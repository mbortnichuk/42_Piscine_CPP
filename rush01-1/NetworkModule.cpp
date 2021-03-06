/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:03 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:05 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(void):height(4) { return; }

NetworkModule::~NetworkModule(void) { return; }

int NetworkModule::getHeight(void)const {
	return (this->height);
}

void NetworkModule::show(int y) {
	void *oldP[1024];
	size_t oldLength = sizeof(struct ipstat), newLength = 0;
	void *newP = NULL;

	sysctlbyname("net.inet.ip.stats", oldP, &oldLength, newP, newLength);

	struct ipstat *g = (struct ipstat*)oldP;

	start_color();
	init_pair(3, COLOR_WHITE, COLOR_RED);
	attron(COLOR_PAIR(3));
	mvprintw(y, 0, "[*]------------  NETWORK   -----------[*]");
	attroff(COLOR_PAIR(3));
	mvprintw(y + 1, 0, "IP packets received : %d\n", g->ips_total);
	mvprintw(y + 2, 0, "IP packets sent     : %d\n", g->ips_localout);
	attron(COLOR_PAIR(3));
	mvprintw(y + 3, 0, "-----------------------------------------");
	attroff(COLOR_PAIR(3));
}
