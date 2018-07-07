/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:59:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 19:59:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	~NinjaTrap();

	void	ninjaShoebox(ClapTrap & ref);
	void	ninjaShoebox(ScavTrap & ref);
	void	ninjaShoebox(FragTrap & ref);
	void	ninjaShoebox(NinjaTrap & ref);
};

#endif
