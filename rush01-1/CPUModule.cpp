/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:15:19 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:15:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"

CPUModule::CPUModule(void) : height(6) {
	size_t	length = sizeof(this->CPU);
	sysctlbyname("machdep.cpu.brand_string", &this->CPU, &length, NULL, 0);
	sysctlbyname("hw.ncpu", &this->nCPU, &length, NULL, 0);

	this->sysTicks = 0;
	this->usrTicks = 0;
	this->idleTicks = 0;
	this->prevIdleTicks = 0;
	this->prevUsrTicks = 0;
	this->prevSysTicks = 0;
	this->counter = HOST_CPU_LOAD_INFO_COUNT;

	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->cpuInfo), &this->counter) == KERN_SUCCESS) {
		this->prevUsrTicks = this->cpuInfo.cpu_ticks[0];
		this->prevSysTicks = this->cpuInfo.cpu_ticks[1];
		this->prevIdleTicks = this->cpuInfo.cpu_ticks[2];
	}
}

void	CPUModule::show(int y) {
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->cpuInfo), &this->counter) == KERN_SUCCESS) {
		this->usrTicks = this->cpuInfo.cpu_ticks[0] - this->prevUsrTicks;
		this->sysTicks = this->cpuInfo.cpu_ticks[1] - this->prevSysTicks;
		this->idleTicks = this->cpuInfo.cpu_ticks[2] - this->prevIdleTicks;
		this->prevUsrTicks = this->cpuInfo.cpu_ticks[0];
		this->prevSysTicks = this->cpuInfo.cpu_ticks[1];
		this->prevIdleTicks = this->cpuInfo.cpu_ticks[2];

		start_color();
		init_pair(1, COLOR_BLACK, COLOR_YELLOW);
		attron(COLOR_PAIR(1));
		mvprintw(y, 0, "[*]--------------  CPU  --------------[*]");
		attroff(COLOR_PAIR(1));
		mvprintw(y + 1, 1, "%s", this->CPU);
		mvprintw(y + 2, 1, "User               : %.2f%%", static_cast<float>(this->usrTicks) / this->nCPU);
		mvprintw(y + 3, 1, "Sys                : %.2f%%", static_cast<float>(this->sysTicks) / this->nCPU);
		mvprintw(y + 4, 1, "Idle               : %.2f%%", static_cast<float>(this->idleTicks) / this->nCPU);
		attron(COLOR_PAIR(1));
		mvprintw(y + 5, 0, "-----------------------------------------");
		attroff(COLOR_PAIR(1));
	}
}

CPUModule::~CPUModule(void) { return; }

int		CPUModule::getHeight(void)const { return (this->height); }