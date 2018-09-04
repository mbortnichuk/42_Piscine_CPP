/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:19:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:19:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <sys/socketvar.h>
# include <netinet/ip.h>
# include <netinet/ip_var.h>

# include "MonitorModule.hpp"

class NetworkModule:public MonitorModule {
public:
	NetworkModule(void);
	virtual ~NetworkModule(void);
	virtual void show(int y);
	virtual int getHeight(void)const;

private:
	int height;

	NetworkModule& operator=(NetworkModule const & rhs);
	NetworkModule(NetworkModule const & src);
};

#endif
