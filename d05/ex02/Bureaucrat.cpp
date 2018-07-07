/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat & a): _name(a.getName())
{
    if (a.getGrade() < 1)
        throw GradeTooHighException();
    else if (a.getGrade() > 150)
        throw GradeTooLowException();
    _grade = a.getGrade();
}

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & a)
{
    _grade = a.getGrade();
    return *this;
}

std::string const       Bureaucrat::getName() const { return _name; }
int                     Bureaucrat::getGrade() const { return _grade; }

Bureaucrat::~Bureaucrat()
{}


std::ostream & operator << (std::ostream & o, Bureaucrat const & a)
{
    return o << "<" << a.getName() << ">, bureaucrat grade <" << a.getGrade() << ">.";
}


Bureaucrat& Bureaucrat::operator++()  
{  
    --_grade;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    return *this;  
}  
  
Bureaucrat Bureaucrat::operator++(int)  
{  
    Bureaucrat temp = *this;  
    ++*this;  
    return temp;  
}

Bureaucrat& Bureaucrat::operator--()  
{  
    ++_grade;
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    return *this;  
}  
  
Bureaucrat Bureaucrat::operator--(int)  
{  
    Bureaucrat temp = *this;  
    ++*this;  
    return temp;  
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("*** The grade gets too high, max level 1 ***");  
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("*** The grade gets too low, min level = 150 ***");  
}

bool        Bureaucrat::signForm(const Form & ref) const
{
    if (ref.getIndicate())
    {
        std::cout << "<" << _name << "> signs <" << ref.getName() << ">." << std::endl;
        return true;
    }  
    else
    {
        std::cout << "<" << _name << "> cannot sign <" << ref.getName()
        << "> because he didn't see this doc or he doesn't have level" << std::endl;
    }
    return false;
        
}

void                 Bureaucrat::increment()
{
    ++*this;
}
void                 Bureaucrat::decrement()
{
    --*this;
}

void        Bureaucrat::executeForm(Form const & form)
{
    if (form.getIndicate() && getGrade() < form.getLevelExecute())
        std::cout << getName() << " executes " << form.getName() << std::endl;
    else
        throw Form::GradeTooLowException();
}



