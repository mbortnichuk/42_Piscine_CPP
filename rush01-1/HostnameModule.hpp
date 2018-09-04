/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:18:41 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:18:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

# include <sys/sysctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <unistd.h>

# include "MonitorModule.hpp"

class HostnameModule:public MonitorModule {
public:
	HostnameModule(void);
	virtual ~HostnameModule(void);
	virtual void show(int y);
	virtual int getHeight(void)const;

private:
	HostnameModule(HostnameModule const & src);
	HostnameModule& operator=(HostnameModule const & rhs);

	int height;
};

#endif
