/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:28:05 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 12:28:06 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cast.hpp"

int     main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    Cast   myClass;

    int i1 = std::atoi(argv[1]);

    myClass.castChar(argv[1], i1);
    myClass.castInt(argv[1]);
    myClass.castFloat(argv[1], i1);
    myClass.castDouble(argv[1], i1);


    return 0;
}
