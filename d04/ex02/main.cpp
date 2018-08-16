/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:08:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:08:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main() {
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* tom = new TacticalMarine;
 	ISpaceMarine* jim = new AssaultTerminator;
 	ISpaceMarine* bim = new AssaultTerminator;

 	ISpaceMarine* cook = NULL;
	ISquad* vlc = new Squad;
	ISquad* v2 = vlc;

	ISquad* v3(v2);
	
	vlc->push(bob);
	vlc->push(jim);
	vlc->push(jim);
	vlc->push(jim);
	vlc->push(tom);
	vlc->push(bim);
	vlc->push(cook);

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	for (int i = 0; i < v2->getCount(); ++i)
	{
		ISpaceMarine* cur = v2->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	for (int i = 0; i < v3->getCount(); ++i)
	{
		ISpaceMarine* cur = v3->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;
	// while (1);
	return 0; 
}
