/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
# define INTERN_CPP
# include <iostream>
//# include "Form.cpp"

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"


class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;


class Intern
{
private:
    int age;
public:
    Intern();
    ~Intern();
    Intern(Intern const & ref);
    Intern& operator= (Intern const & ref);

    class FormException: public std::exception
    {
    public:
        const char* what() const throw();
    };

    Form*   makeForm(std::string nameForm, std::string targetName);

    int getAge() const;

    void setAge(int age);
};


#endif