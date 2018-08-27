/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Champ.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 17:41:11 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/18 17:41:12 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMP_HPP
# define CHAMP_HPP

# include "Enemy.hpp"
# include "Champ.hpp"
class Champ:public Object {
public:
	Champ(Playground & pl);
	Champ(Champ const & src);
	~Champ(void);

	void inputDir(int pl);
	void printIt(Playground & pl)const;
	void move(Playground & pl);
	void checkEnemy(Enemy* enemy, int i, Playground & pl);
	void printLives(Playground & pl)const;
	Champ& operator=(Champ const & rhs);

	int inp;

private:
	Champ(void);
	std::string _name;
};

#endif
