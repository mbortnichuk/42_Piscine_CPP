/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "Form.hpp"


class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm();

    explicit PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const & ref);
    PresidentialPardonForm& operator= (PresidentialPardonForm const & ref);
    ~PresidentialPardonForm();

    void    execute(Bureaucrat const & executor) const;

};

#endif