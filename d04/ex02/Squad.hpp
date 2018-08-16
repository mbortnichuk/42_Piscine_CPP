/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:14:24 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:14:25 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
#define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad:public ISquad {
public:
	Squad(void);
	Squad(Squad & src);
	~Squad(void);

	int				getCount()const;
	ISpaceMarine*	getUnit(int);
	int				push(ISpaceMarine*);
	Squad& operator=(Squad & rhs);
private:
	ISpaceMarine**	_squad;
	int				_count;
};

#endif
