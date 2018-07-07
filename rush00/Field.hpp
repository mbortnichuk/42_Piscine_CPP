/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Field.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:14:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:14:23 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_HPP
# define FIELD_HPP

# include <ncurses.h>
# include <iostream>
# include "Champ.hpp"
# include "SpaceShip.hpp"
# include "GameCore.hpp"

extern clock_t G_TIME;

class Field {
private:
	int xMax;
	int yMax;
	clock_t time;
public:
	Field();
	Field(Field const & obj);
	~Field();

	Field & operator=(Field const & obj);

	void sleep(unsigned long int sleep);
	void printSummary(Champ *c);
	void updateScreen(Champ *c, SpaceShip s[], GameCore stars[], GameCore champBullets[], GameCore enemyBullets[], GameCore explode[]);
	void printBorders();
	bool endGame(int score);

	int getXmax()const;
	int getYmax()const;

	void setXmax(int xMax);
	void setYmax(int yMax);

	bool menu();

	void loadField();
};

#endif
