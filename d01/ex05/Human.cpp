/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 20:44:30 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 20:44:31 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : brain() {
}

std::string Human::identify() {
	return (const_cast<Brain&>(brain).identify());
}

Brain& Human::getBrain() {
	return (const_cast<Brain&>(brain));
}
