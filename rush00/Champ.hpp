/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Champ.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:15:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/22 13:15:09 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMP_HPP
# define CHAMP_HPP

# include "SpaceShip.hpp"

class Champ : public SpaceShip {
public:
	Champ();
	Champ(char *s);
	Champ(Champ const & obj);
	Champ & operator=(Champ const & obj);
	~Champ();

	int getScore()const;
	int getLive()const;
	int getLostLife()const;
	int	getLevel()const;

	void	setScore(int score);
	void	setLive(int lives);
	void	setLostLife(int lostLife);
	void	setLevel(int score);

	void collide();

private:
	int score;
	int lives;
	int lostLife;
	int	level;
};

#endif
