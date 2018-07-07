/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameCore.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:16:21 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:16:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CORE_HPP
# define GAME_CORE_HPP

# include "ncurses.h"
# include <iostream>

class GameCore {
public:
	GameCore();
	GameCore(GameCore const & obj);
	GameCore & operator=(GameCore const & obj);
	~GameCore();

	void collide();

	int getXpos()const;
	int getYpos()const;
	char *getDCh()const;
	int getRSpeed()const;
	int getRespawnTime()const;

	void setXpos(int xpos);
	void setYpos(int ypos);
	void setDCh(char *dCh);
	void setRSpeed(int rsp);
	void setRespawnTime(int rst);

	bool isCollided()const;
	void setCollided(bool collided);

protected:
	int xpos;
	int ypos;
	char* dCh;
	bool collided;
	int rsp;
	int rst;
};

#endif
