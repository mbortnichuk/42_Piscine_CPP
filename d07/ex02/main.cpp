/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:20:40 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/28 14:20:41 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "Array.hpp"

int				main(void)
{
	Array<int>		array1(20);
	Array<int>		array2;

	std::cout << "First arr size: " << array2.size() << std::endl;
	std::cout << "Empty arr size: " << array1.size() << std::endl;

	array1[10] = 42;
	std::cout << "arr1[10] : " << array1[10] << std::endl;
	array1[11] = 84;
	std::cout << "arr1[11] : " << array1[11] << std::endl;

	array2 = array1;
	std::cout << "Copying arr1 in arr2..." << std::endl;
	array1[10] = 0;
	array1[11] = 0;

	std::cout << "arr2[10] : " << array2[10] << std::endl;
	std::cout << "arr2[11] : " << array2[11] << std::endl;

	std::cout << "Trying to set arr1[30]" << std::endl;
	try {
		array1[30] = 42;
		std::cout << "USPEH!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "FAIL! : " << e.what() << std::endl;
	}

	return (0);
}
