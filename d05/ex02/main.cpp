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

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int         main()
{
    try
    {
    //     Bureaucrat      a1("first", 1);
    //     Bureaucrat      a2("second", 2);
    //     Bureaucrat      a3 = a1;
    //     Bureaucrat      a4("four", 4);
    //     //Bureaucrat      a0("Zero", 0);
         //Bureaucrat      a("minNUMBER", 152);
    //     //Bureaucrat      a10 = --a;

    //  --a;
      
    //     std::cout << a1 << std::endl;
    //     std::cout << a2 << std::endl;
    //     std::cout << a3 << std::endl;
    //     std::cout << a4 << std::endl;
          // std::cout << a << std::endl;
    //     //std::cout << a10 << std::endl;
    //     std::cout << "**************************" << std::endl;
    //     Form form1("zarplate", 10, 150);
    //     Bureaucrat bureaucrat1("top", 1);
    //     Bureaucrat bureaucrat2("not top", 15);
  

        
        
       
        // form1.beSigned(bureaucrat1);

        
       // bureaucrat1.signForm(form1);
        // bureaucrat2.signForm(form1);

        std::cout <<  "************" << std::endl;
        Bureaucrat      execute("executor", 130);
        Bureaucrat      boss("boss", 112);


        ShrubberyCreationForm   shrubbery111("work_in_garden");


        shrubbery111.beSigned(boss);
        shrubbery111.execute(execute);
        execute.executeForm(shrubbery111);
//
//        std::cout <<  boss << std::endl;
//        std::cout <<  execute << std::endl;
//        std::cout <<  shrubbery111 << std::endl;


        std::cout <<  "=============" << std::endl;

        Bureaucrat      execute1("Robotimizator", 40);
        Bureaucrat      boss1("Boss", 70);
        RobotomyRequestForm robotForm("Grabgrab");
        robotForm.beSigned(boss1);
        robotForm.execute(execute1);
        execute1.executeForm(robotForm);
//        std::cout <<  boss1 << std::endl;
//        std::cout <<  execute1 << std::endl;
//        std::cout <<  robotForm << std::endl;

        std::cout <<  "///////////////" << std::endl;
        PresidentialPardonForm pomilovanie("Vinoven");
        Bureaucrat      execute2("Judge", 10);
        Bureaucrat      boss2("Boss", 2);
        pomilovanie.beSigned(boss2);
        pomilovanie.execute(execute2);
        execute2.executeForm(pomilovanie);


        //std::cout << a << std::endl;

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