/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 20:44:43 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 20:44:44 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iomanip>
#include <sstream>

Brain::Brain() {
	val = "Brain";
}

std::string Brain::identify() {
	std::stringstream s;

	s << this;

	return s.str();
}
