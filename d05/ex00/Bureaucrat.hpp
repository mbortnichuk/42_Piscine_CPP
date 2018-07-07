/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
private:
	std::string const name;
	int grade;
	Bureaucrat();
public:
	class GradeTooHighException: public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what() const throw();
	};

	Bureaucrat(Bureaucrat & b);
	Bureaucrat(std::string name, int grade);
	Bureaucrat & operator=(Bureaucrat const & b);

	std::string const getName()const;
	int getGrade()const;

	~Bureaucrat();

	void increment();
	void decrement();

	Bureaucrat& operator++();
	Bureaucrat operator++(int);
	Bureaucrat& operator--();
	Bureaucrat operator--(int);
};

std::ostream & operator << (std::ostream & os, Bureaucrat const & b);

#endif
