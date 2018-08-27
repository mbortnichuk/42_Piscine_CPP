/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:57:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 10:57:32 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <unistd.h>
# include "Playground.hpp"
# include <string>

class Object {
public:
	Object(void);
	Object(int posx, int posy, int dirx, int diry, int speed, int hp, std::string form);
	Object(Object const & src);
	virtual					~Object(void);
	int 					getX(void)const;
	int 					getY(void)const;
	int 					getdirX(void)const;
	int 					getdirY(void)const;
	int 					getSpeed(void)const;
	int						getsizeX(void)const;
	int						getsizeY(void)const;
	std::string&			getForm(void)const;
	int						getHP(void)const;
	void					setHP(int i);
	void					setPos(int x, int y);
	void					setDir(int x, int y);
	void					setSpeed(int s);
	void					setForm(std::string form);
	void					move(Playground& win);
	virtual void			printit(Playground& win)const;
	virtual void			colision(Object& obj);
	void					explode(Playground& win, int F);
	void					print_score(Playground & win)const;
	void					setScore(void);
	void					setScoreZero(void);
	int						getScore(void);
	Object& operator=(Object const & rhs);

protected:
	int			m_posx;
	int			m_posy;
	int			m_dirx;
	int			m_diry;
	int			m_speed;
	int			m_sizex;
	std::string	m_form;
	int			m_hp;
	int static	m_score;
};

#endif

