/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:02:32 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 19:02:33 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string s = "HI THIS IS BRAIN";
	std::string* sPtr = &s;
	std::string& sRef = s;

	std::cout << "*sPtr: " << *sPtr << std::endl;
	std::cout << "&sRef: " << sRef << std::endl;
	return 0;
}
