/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorDisplay.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:36:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/03 15:36:33 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORDISPLAY_HPP
# define MONITORDISPLAY_HPP

class MonitorDisplay {
public:
	virtual void init(void) = 0;
	virtual int getKey(CPUModule const & cpu, HostnameModule const & hostname, TimeModule const & time, NetworkModule const & net, RAMModule const & ram, OSInfoModule const & os) = 0;
	virtual void start(void) = 0;
};

#endif
