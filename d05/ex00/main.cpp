/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat b1("one", 1);
		Bureaucrat b2("two", 2);
		Bureaucrat b3 = b1;
		Bureaucrat b4("three", 4);
		Bureaucrat b0("zero", 0);
		Bureaucrat b("minNbr", 150);

		b1.increment();

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
