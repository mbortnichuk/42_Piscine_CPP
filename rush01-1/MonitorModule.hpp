/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MonitorModule.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 16:17:18 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 16:17:19 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORMODULE_HPP
# define MONITORMODULE_HPP

# include <ncurses.h>

class MonitorModule {
public:
	virtual void show(int y) = 0;
	virtual int getHeight(void)const = 0;
};

#endif
