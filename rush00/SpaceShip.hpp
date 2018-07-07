/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:14:02 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:14:03 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_SHIP_HPP
# define SPACE_SHIP_HPP

# include "GameCore.hpp"

class SpaceShip : public GameCore {
public:
	SpaceShip();
	SpaceShip(char* s);
	SpaceShip(SpaceShip const & obj);
	SpaceShip & operator=(SpaceShip const & src);
	~SpaceShip();

	void shoot(GameCore arrBullers[]);
	void initiateBullets(GameCore arrBullers[], int count, char *bullet);
};

#endif
