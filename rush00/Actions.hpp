/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actions.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:16:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:16:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_HPP
# define ACTIONS_HPP

# include "Champ.hpp"
# include "SpaceShip.hpp"
# include "GameCore.hpp"

class Actions {
private:
	int action;
public:
	Actions();
	Actions(Actions const & obj);
	~Actions();

	Actions & operator=(Actions const & obj);

	int getActions()const;

	void setAction(int ch);
	void set_action(int action);

	bool applyAct(Champ *c, SpaceShip s[], GameCore stars[], GameCore champBullets[], GameCore enemyBullets[], GameCore explode[]);
	void checkCollision(Champ *c1, SpaceShip s1[], GameCore champBullets[], GameCore enemyBullets[]);
};

#endif
