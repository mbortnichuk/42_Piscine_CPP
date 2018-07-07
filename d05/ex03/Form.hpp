/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string           name;
    bool                        indicate;
    const int                   levelSing;
    const int                   levelExecute;
    Form();
public:

    Form(std::string name, int levSing, int levExec);
    Form(Form const & a);
    Form& operator= (Form const & a);

    virtual ~Form();

    std::string         getName()const;
    bool                getIndicate()const;
    int                 getLevelSign()const;
    int                 getLevelExecute()const;
    void                beSigned(Bureaucrat & ref);
    void                setIndicate(bool a);


    class GradeTooLowException: public std::exception
    {
    public:
        const char* what() const throw();
    };
    class GradeTooHighException: public std::exception
    {
    public:
        const char* what() const throw();
    };


    virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&   operator << (std::ostream & o, Form const & ref);


#endif

