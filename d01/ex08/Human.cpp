/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:13:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 15:13:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{}

Human::~Human()
{}

void	Human::meleeAttack(std::string const & targert)
{
	std::cout << "***** Human -> meleeAttack *****" << std::endl;
	std::cout << targert << std::endl;
}

void	Human::rangedAttack(std::string const & targert)
{
	std::cout << "***** Human -> rangedAttack *****" << std::endl;
	std::cout << targert << std::endl;
}

void	Human::intimidatingShout(std::string const & targert)
{
	std::cout << "***** Human -> intimidatingShout *****" << std::endl;
	std::cout << targert << std::endl;
}

void	Human::action(std::string const & action_name, std:: string const & target)
{
	typedef void (Human::*myFuncType)(std::string const & targert);

	myFuncType myFunc[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string name[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	for(int i = 0; i < 3; i++)
	{
		if(name[i] == action_name)
			(this->*myFunc[i])(target);
    }
}
