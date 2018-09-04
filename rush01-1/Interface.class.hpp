/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:18:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:18:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_CLASS_HPP
# define INTERFACE_CLASS_HPP

# include <curses.h>
# include <ctime>
# include <unistd.h>
# include <iostream>
# include <string>

# include "CPUModule.hpp"
# include "HostnameModule.hpp"
# include "TimeModule.hpp"
# include "NetworkModule.hpp"
# include "RAMModule.hpp"
# include "OSInfoModule.hpp"
# include "MonitorDisplay.hpp"

# define ESC 27
# define RES 330
# define ONE 49
# define TWO 50
# define THR 51
# define FOR 52
# define FIV 53
# define SIX 54

class Interface:public MonitorDisplay {
public: 
	Interface(void);
	virtual ~Interface(void);
	virtual void init(void);
	virtual void start(void);
	virtual int getKey(CPUModule const & cpu, HostnameModule const & hostname, TimeModule const & time, NetworkModule const & net, RAMModule const & ram, OSInfoModule const & os);

private:
	int pos[6];
	int y;
	int mod;
	Interface(Interface const & inter);
	Interface& operator=(Interface const & inter);
};

#endif
