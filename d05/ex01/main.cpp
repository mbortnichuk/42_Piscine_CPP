/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:12:01 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/25 19:12:01 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int         main()
{
    try
    {
        Bureaucrat      a1("first", 1);
        Bureaucrat      a2("second", 2);
        Bureaucrat      a3 = a1;
        Bureaucrat      a4("four", 4);
        //Bureaucrat      a0("Zero", 0);
        Bureaucrat      a("minNUMBER", 150);
        //Bureaucrat      a10 = --a;

      //  --a;
      
        std::cout << a1 << std::endl;
        std::cout << a2 << std::endl;
        std::cout << a3 << std::endl;
        std::cout << a4 << std::endl;
        std::cout << a << std::endl;
        //std::cout << a10 << std::endl;
        std::cout << "**************************" << std::endl;
        Form form1("zarplate", 10, 150);
        Bureaucrat bureaucrat1("top", 1);
        Bureaucrat bureaucrat2("not top", 15);
  

        
        
       
        form1.beSigned(bureaucrat1);

        
       // bureaucrat1.signForm(form1);
        bureaucrat2.signForm(form1);


    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Standart exception" << std::endl;
    }

}