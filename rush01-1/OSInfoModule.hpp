/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSInfoModule.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:32 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

# include <string>
# include <sys/sysctl.h>
# include <iostream>
# include <fstream>
# include <algorithm>

# include "MonitorModule.hpp"

class OSInfoModule:public MonitorModule {
public:
	OSInfoModule(void);
	virtual ~OSInfoModule(void);
	virtual void show(int y);
	virtual int getHeight(void)const;

private:
	int height;

	std::string osRelease;
	std::string osType;
	std::string osHost;

	OSInfoModule(OSInfoModule const & src);
	OSInfoModule& operator=(OSInfoModule const & rhs);
};

#endif
