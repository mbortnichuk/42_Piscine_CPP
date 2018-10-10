/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:27 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule(void):height(6) {
	size_t length;
	char line[1024];

	length = sizeof(line);
	sysctlbyname("kern.ostype", line, &length, NULL, 0);
	this->osType = line;
	length = sizeof(line);
	sysctlbyname("kern.osrelease", line, &length, NULL, 0);
	this->osRelease = line;

	std::ifstream ifs("/System/Library/CoreServices/SystemVersion.plist");
	std::string buff;

	while (std::getline(ifs, buff)) {
		if (buff.find("ProductVersion") != std::string::npos) {
			if (std::getline(ifs, buff))
				this->osHost = buff.substr(9, 7);
			else
				buff = "No version founded";
		}
	}
}

OSInfoModule::~OSInfoModule(void) { return; }

int OSInfoModule::getHeight(void)const { return (this->height); }

void OSInfoModule::show(int y) {
	start_color();
	init_pair(4, COLOR_BLACK, COLOR_CYAN);
	attron(COLOR_PAIR(4));
	mvprintw(y, 0, "[*]------------  OS INFO   -----------[*]");
	attroff(COLOR_PAIR(4));
	mvprintw(y + 1, 1, "Kernel name        : %s", this->osType.c_str());
	mvprintw(y + 2, 1, "Kernel version     : %s", this->osRelease.c_str());

	if (atoi(this->osRelease.c_str()) == 14)
		mvprintw(y + 3, 1, "Product name:    Yosemite");
	else if (atoi(this->osRelease.c_str()) == 13)
		mvprintw(y + 3, 1, "Product name:     Maverik");

	mvprintw(y + 4, 1, "Product version    : %s", this->osHost.c_str());
	attron(COLOR_PAIR(4));
	mvprintw(y + 5, 0, "-----------------------------------------");
	attroff(COLOR_PAIR(4));
}
