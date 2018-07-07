/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45) {}


RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ref) : Form(ref.getName(), 72, 45)
{}

RobotomyRequestForm& RobotomyRequestForm::operator= (RobotomyRequestForm const & ref)
{
    setIndicate(ref.getIndicate());
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << "Brrraaaa Brrrrrrraaaa  rrr...." << std::endl;
    srand(time(0));
    if (std::rand() % 2 == 0)
        std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
    else
        std::cout << "It's failure" << std::endl;

}
