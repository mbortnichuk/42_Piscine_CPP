/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 22:13:40 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/19 22:13:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap {
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
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();

	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	challengeNewcomer();

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
