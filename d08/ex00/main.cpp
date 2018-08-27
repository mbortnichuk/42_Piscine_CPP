/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:31:33 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/17 10:31:35 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <set>
#include <list>
#include <vector>

int main() {
	std::cout << "*** SET ***" << std::endl;
	int intArray[] = {10, 20, 30, 40, 50, 60};
	std::set<int> first(intArray, intArray + 6);
	try {
		easyfind(first, 70);
	} catch (std::exception) {
		std::cout << "Not found." << std::endl;
	}

	std::cout << "*** LIST ***" << std::endl;
	std::list<int> list1;
	list1.push_back(9);
	list1.push_back(8);
	list1.push_back(7);
	list1.push_back(6);
	list1.push_back(5);
	try {
		easyfind(list1, 6);
	} catch (std::exception) {
		std::cout << "Not found." << std::endl;
	}

	std::cout << "*** VECTOR ***" << std::endl;
	std::vector<int> vec;
	vec.push_back(1234);
	vec.push_back(2);
	vec.push_back(12);
	vec.push_back(32);
	vec.push_back(64);
	vec.push_back(88);
	vec.push_back(1234);
	try {
		easyfind(vec, 1234);
	} catch (std::exception) {
		std::cout << "Not found." << std::endl;
	}

	return 0;

}
