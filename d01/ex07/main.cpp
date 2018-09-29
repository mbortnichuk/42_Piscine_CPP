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

#include <iostream>
#include <fstream>
#include "Replace.hpp"

void 	error(std::string s) {
	std::cout << s + '\n';
	std::exit(1);
}

int main(int argc, char **argv) {
	if (argc != 4)
		error("Usage: ./replace fileName s1 s2");
	Replace replace = Replace(argv[2], argv[3], argv[1]);
	replace.validation();	
	if ((replace.replaceFile()) == false)
		error("Error file");
}
