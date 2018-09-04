/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimeModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:16:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:16:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP

# include <ctime>
# include "MonitorModule.hpp"

class TimeModule:public MonitorModule {
public:
	TimeModule(void);
	virtual ~TimeModule(void);
	virtual int getHeight(void)const;
	virtual void show(int y);

private:
	int height;
	TimeModule& operator=(TimeModule const & rhs);
	TimeModule(TimeModule const & src);
};

#endif
