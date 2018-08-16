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
# include "Form.hpp"

class Form;

class  Bureaucrat
{
private:
    std::string const       _name;
    int                     _grade;
    Bureaucrat();
public:
    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();
    };
    
    Bureaucrat(Bureaucrat & a);
    Bureaucrat(std::string name, int grade);
    Bureaucrat & operator = (Bureaucrat const & a);

    std::string const       getName() const;
    int                     getGrade() const;

    ~Bureaucrat();

    void                    increment();
    void                    decrement();

    Bureaucrat& operator++ ();
    Bureaucrat operator++ (int);
    Bureaucrat& operator-- ();
    Bureaucrat operator-- (int);


    void        signForm(Form & ref);
};

std::ostream & operator << (std::ostream & o, Bureaucrat const & a);

#endif
