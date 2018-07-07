/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:24:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 15:24:43 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak() {
	std::string *panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}

int main(void) {
	memoryLeak();
	return 0;
}
