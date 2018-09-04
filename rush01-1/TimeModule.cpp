/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:16:18 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:16:19 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TimeModule.hpp"

TimeModule::TimeModule(void):height(3) {
	return;
}

TimeModule::~TimeModule(void) {
	return;
}

int TimeModule::getHeight(void)const {
	return (this->height);
}

void TimeModule::show(int y) {
	time_t rawTime;
	struct tm* timeInfo;
	char buff[26];

	time(&rawTime);
	timeInfo = localtime(&rawTime);
	strftime(buff, 26, "%c", timeInfo);
	mvprintw(y, 0, "#------- DATE -------#");
	mvprintw(y + 1, 0, " %s", buff);
}
