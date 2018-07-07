/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & ref) : Form(ref)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (ShrubberyCreationForm const & ref)
{
    setIndicate(ref.getIndicate());
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::ofstream output(getName() + "_shrubbery");


        output << "    oxoxoo    ooxoo" << std::endl;
        output << "  ooxoxo oo  oxoxooo" << std::endl;
        output << " oooo xxoxoo ooo ooox" << std::endl;
        output << " oxo o oxoxo  xoxxoxo" << std::endl;
        output << "  oxo xooxoooo o ooo" << std::endl;
        output << "    ooo\\oo\\  /o/o" << std::endl;
        output << "        \\  \\/ /" << std::endl;
        output << "         |   /" << std::endl;
        output << "         |  |" << std::endl;
        output << "         | D|" << std::endl;
        output << "         |  |" << std::endl;
        output << "         |  |" << std::endl;
        output << "  ______/____\\____" << std::endl;

        output.close();
}


