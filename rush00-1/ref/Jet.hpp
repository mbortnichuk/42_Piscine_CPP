/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jet.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:04:37 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:04:39 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JET_HPP
# define JET_HPP

# include "Object.hpp"
# include "Champ.hpp"
# include "Enemy.hpp"
# include "Playground.hpp"

class Jet:public Object {
public:
	Jet(int N, std::string form);
	Jet(Jet const & src);
	~Jet(void);
	Jet* getJet(void)const;
	int	getIndex(void)const;
	int	getMax(void)const;
	void printit(Playground& win)const;
	void move(Playground& win);
	void activate(int xpos, int ypos, int input);
	void checkDamages(Enemy*, int N, Playground& win);
	void print_chargeur(Playground & win);
	Jet& operator=(Jet const & rhs);
	int			check_m_dispo(void);

private:
	Jet(void);
	Jet* m_Jets;
	int		 m_max;
	int		 m_index;
};

#endif

