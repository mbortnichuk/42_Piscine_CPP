/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:38:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/19 16:38:32 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap {
private:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	maxHitPoints;
	unsigned int	energyPoints;
	unsigned int	maxEnergyPoints;
	unsigned int	level;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	armorDamageReduction;
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	vaulthunter_dot_exe(std::string const & target);

	//setter -> void (unsigned int val)
	void	setHitPoints(unsigned int val);
	void	setMaxHitPoints(unsigned int val);
	void	setEnergyPoints(unsigned int val);
	void	setMaxEnergyPoints(unsigned int val);
	void	setLevel(unsigned int val);
	void	setMeleeAttackDamage(unsigned int val);
	void	setRangedAttackDamage(unsigned int val);
	void	setArmorDamageReduction(unsigned int val);

	//getter -> unsigned int ()const
	unsigned int	getHitPoints()const;
	unsigned int	getMaxHitPoints()const;
	unsigned int	getEnergyPoints()const;
	unsigned int	getMaxEnergyPoints()const;
	unsigned int	getLevel()const;
	unsigned int	getMeleeAttackDamage()const;
	unsigned int	getRangedAttackDamage()const;
	unsigned int	getArmorDamageReduction()const;
};

#endif
