/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:43:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 14:43:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string input, std::string output) {
	this->input = input;
	this->output = output;
}

void	Replace::replace(std::string s1, std::string s2) {
	std::string buffer;
	std::fstream input(this->input);

	if (s1 == "") {
		std::cout << "Wrong input \"\"" << std::endl;
		return ;
	}
	if (!input.is_open()) {
		std::cout << "File is not available" << std::endl;
		return ;
	}
	std::ofstream output(this->output);
	while (getline(input, buffer)) {
		size_t p = buffer.find(s1, 0);
		while (p != std::string::npos) {
			buffer.replace(p, s1.length(), s2);
			p = buffer.find(s1, p + s2.length());
		}
		output << buffer << std::endl;
	}
	input.close();
	output.close();
}

Replace::~Replace() {
	std::cout << this->output << " file has been created" << std::endl;
}
