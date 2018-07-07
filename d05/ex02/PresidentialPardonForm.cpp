/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
# include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & ref) : Form(ref)
{}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const & ref)
{
    setIndicate(ref.getIndicate());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

