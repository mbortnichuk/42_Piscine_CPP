/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:56:38 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 14:56:39 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string breed, int age) : _name(name), _breed(breed), _age(age) {
	std::cout << "Pony " << _name << " is born" << std::endl;
}

Pony::~Pony() {
	std::cout << "Pony " << _name << " is dead" << std::endl;
}
