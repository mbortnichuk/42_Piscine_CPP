/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Playground.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:46:19 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/17 17:46:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYGROUND_HPP
# define PLAYGROUND_HPP

# include <ncurses.h>
# include <cstdlib>

class Playground {
public:
	Playground(void);
	Playground(Playground const & src);
	~Playground();

	void takeWindSize(void);
	int getX(void)const;
	int getY(void)const;
	WINDOW* getWindow(void)const;
	void printBorder();
	void setClr(int i);

	Playground& operator=(Playground const & rhs);

protected:
	int minSizeX;
	int minSizeY;
	int _clr;
	WINDOW* minWin;
};

#endif
