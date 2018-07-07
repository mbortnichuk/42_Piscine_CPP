/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:36:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 18:36:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int         main()
{
    try
    {
        Intern  someRandomIntern;
        Form *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    catch (Intern::FormException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Standart exception" << std::endl;
    }

}