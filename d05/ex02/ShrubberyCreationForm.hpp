/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
    
public:
    ShrubberyCreationForm();

    explicit ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & ref);
    ShrubberyCreationForm& operator= (ShrubberyCreationForm const & ref);
    ~ShrubberyCreationForm();

    void    execute(Bureaucrat const & executor) const;
};


#endif
