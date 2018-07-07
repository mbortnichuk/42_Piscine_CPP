/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:20:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 17:20:43 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <ctime>
# include "Zombie.hpp"

class ZombieEvent {
private:
	std::string	_type;
public:
	ZombieEvent(){
	};
	void	setZombieType(std::string type);
	Zombie* newZombie(std::string name);
	Zombie* randomZombie();
	~ZombieEvent();
};

#endif
