/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:13:27 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 15:13:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
#include <iostream>

class Human
{
private:
	void	meleeAttack(std::string const & targert);
	void	rangedAttack(std::string const & targert);
	void	intimidatingShout(std::string const & targert);
public:
	Human();
	void	action(std::string const & action_name, std:: string const & target);
	~Human();
};

#endif
