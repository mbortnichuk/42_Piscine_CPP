/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 10:59:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 10:59:42 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Object.hpp"

class Enemy:public Object {
public:
	Enemy(int n);
	Enemy(int n, std::string form);
	Enemy(Enemy const & src);
	~Enemy(void);
	Enemy*	getHorde(void)const;
	int			 	getNum(void)const;
	void		 	printIt(Playground& pl)const;
	void			randomBoom(Playground& pl);
	void			move(Playground& pl);
	void			respawn(void);
	Enemy*		getHorde(void);
	int				getNum(void);
	void			die(Playground& pl);
	// void			attack(Object& trg);
	Enemy& operator=(Enemy const & rhs);

private:
	Enemy(void);
	Enemy*	mHorde;
	int				mNum;
};

#endif
