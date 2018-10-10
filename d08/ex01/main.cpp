/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:10:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/17 11:10:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main() {
	try {
		srand(time(0));
		Span span(100000);

		// span.addNumber(5);
		// span.addNumber(3);
		// span.addNumber(17);
		// span.addNumber(10);
		// span.addNumber(11);

		for (int i = 0; i < 100000; i++)
			span.addNumber(std::rand() & 247483647);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (std::exception) {
		std::cout << "Error" << std::endl;
	}

	return 0;
}
