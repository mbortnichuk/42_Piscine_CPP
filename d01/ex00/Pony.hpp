/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:56:44 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 14:56:45 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony {
private:
	std::string _name;
	std::string _breed;
	int		_age;
public:
	Pony(void);
	Pony(std::string, std::string, int);
	~Pony(void);
};

#endif
