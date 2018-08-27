/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jet.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:46:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/21 13:46:44 by mbortnic         ###   ########.fr       */
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
	Jet(int n, std::string form);
	Jet(Jet const & src);
	~Jet();

	Jet* getJet(void)const;
	int getId(void)const;
	int getMax(void)const;
	void printIt(Playground & pl)const;
	void move(Playground & pl);
	void start(int xPos, int yPos, int inp);
	void checkDamage(Enemy* enemy, int n, Playground & pl);
	void printCharge(Playground & pl);
	int checkMDisp(void);

	Jet& operator=(Jet const & rhs);

private:
	Jet(void);
	Jet* mJets;
	int mMax;
	int mId;
};

#endif
