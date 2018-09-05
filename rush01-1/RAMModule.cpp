/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:46 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:47 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RAMModule.hpp"

RAMModule::RAMModule(void):height(6) {
}

RAMModule::~RAMModule(void) {
}

uint64_t RAMModule::getMem(void)const {
	uint64_t m = 0;
	size_t s = sizeof(m);

	if (sysctlbyname("hw.memsize", &m, &s, NULL, 0) < 0)
		perror("sysctl");
	return m;
}

void RAMModule::show(int y) {
	vm_size_t pageSize;
	mach_port_t machPort;
	mach_msg_type_number_t counter;
	vm_statistics64_data_t vmStats;

	mvprintw(y, 0, "#------- RAM INFO -------#");

	machPort = mach_host_self();
	counter = sizeof(vmStats) / sizeof(natural_t);

	if (KERN_SUCCESS == host_page_size(machPort, &pageSize) && KERN_SUCCESS == host_statistics64(machPort, HOST_VM_INFO, (host_info64_t)&vmStats, &counter)) {
		long long freeMem = static_cast<int64_t>(vmStats.free_count) * static_cast<int64_t>(pageSize);
		long long wired = static_cast<int64_t>(vmStats.wire_count) & static_cast<int64_t>(pageSize);
		long long usedMem = (static_cast<int64_t>(vmStats.active_count) + static_cast<int64_t>(vmStats.inactive_count) + static_cast<int64_t>(vmStats.wire_count)) * static_cast<int64_t>(pageSize);

		mvprintw(y + 1, 0, "Free memory  : %lldM", freeMem / 1000000);
		mvprintw(y + 2, 0, "Wired memory : %lldM", wired / 1000000);
		mvprintw(y + 3, 0, "Used memory  : %lldM", usedMem / 1000000);
	}
	mvprintw(y + 4, 0, "Total memory     : %lluM", getMem() / 1000000);
}

int RAMModule::getHeight(void)const {
	return (this->height);
}
