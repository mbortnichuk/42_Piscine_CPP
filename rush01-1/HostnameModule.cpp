/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:18:37 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:18:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.hpp"

HostnameModule::HostnameModule(void):height(4) { return; }

HostnameModule::~HostnameModule(void) { return; }

void HostnameModule::show(int y) {
	char host[1024];
	size_t length = sizeof(host);
	struct passwd *psswd;

	start_color();
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(2));
	mvprintw(y, 0, "[*]------------  HOSTNAME  -----------[*]");
	attroff(COLOR_PAIR(2));


	if (!sysctlbyname("kern.hostname", &host, &length, NULL, 0))
		mvprintw(y + 1, 1, "	     %s", host);
	psswd = getpwuid(geteuid());
	mvprintw(y + 2, 1, "	         %s", psswd->pw_name);
	attron(COLOR_PAIR(2));
	mvprintw(y + 3, 0, "-----------------------------------------");
	attroff(COLOR_PAIR(2));
}

int HostnameModule::getHeight(void)const { return (this->height); }
