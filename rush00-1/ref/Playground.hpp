/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Playground.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:29:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/23 12:29:44 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYGROUND_HPP
# define PLAYGROUND_HPP

# include <cstdlib>
# include <ncurses.h>

class Playground {
public:
	Playground(void);
	Playground(Playground const & src);
	~Playground(void);
	void	takeSize(void);
	int		getX(void)const;
	int		getY(void)const;
	WINDOW*	getWin(void)const;
	void	printBorder();
	void	setColor(int i);
	Playground& operator=(Playground const & rhs);

protected:
	int		m_sizex;
	int		m_sizey;
	WINDOW* m_win;
	int		_color;
};

#endif

