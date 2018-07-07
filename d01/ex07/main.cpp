/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:50:23 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 14:50:24 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Incorrect amount of data" << std::endl;
		return 1;
	}
	std::string output(av[1]);
	output += ".replace";
	Replace replace(av[1], output);
	replace.replace(av[2], av[3]);
	return 0;
}
