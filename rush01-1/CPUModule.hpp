/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:15:23 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:15:24 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include <iostream>

# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>

# include <sys/sysctl.h>
# include <ncurses.h>

# include "MonitorModule.hpp"

class CPUModule:public MonitorModule {
public:
	CPUModule(void);
	virtual ~CPUModule(void);
	virtual int getHeight(void)const;
	virtual void show(int y);

private:
	CPUModule(CPUModule const & src);
	CPUModule& operator=(CPUModule const & rhs);

	int height;
	char CPU[1024];
	int nCPU;

	unsigned long long prevIdleTicks;
	unsigned long long prevUsrTicks;
	unsigned long long prevSysTicks;
	unsigned long long sysTicks;
	unsigned long long userTicks;
	unsigned long long idleTicks;

	host_cpu_load_info_data_t cpuInfo;
	mach_msg_type_number_t counter;
};

#endif