/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RAMModule.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <sys/types.h>
# include <sys/sysctl.h>
# include <stdio.h>
# include <stdint.h>

# include "MonitorModule.hpp"

class RAMModule:public MonitorModule {
public:
	RAMModule();
	virtual ~RAMModule();
	virtual int getHeight(void)const;
	virtual void show(int y);

private:
	int height;
	uint64_t getMem(void)const;
	RAMModule& operator=(RAMModule const & rhs);
	RAMModule(RAMModule const & src);
};

#endif
