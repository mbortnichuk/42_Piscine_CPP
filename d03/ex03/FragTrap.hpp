/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:53:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/20 19:53:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap:public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
