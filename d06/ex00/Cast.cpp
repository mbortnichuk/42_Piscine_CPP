/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:32:03 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 12:32:04 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Cast.hpp"
#include <iomanip>

char Cast::getC() const {
    return c;
}

void Cast::setC(char c) {
    Cast::c = c;
}

int Cast::getI() const {
    return i;
}

void Cast::setI(int i) {
    Cast::i = i;
}

double Cast::getD() const {
    return d;
}

void Cast::setD(double d) {
    Cast::d = d;
}

float Cast::getF() const {
    return f;
}

void Cast::setF(float f) {
    Cast::f = f;
}

Cast::Cast(const Cast &cast) {
    c = cast.getC();
    i = cast.getI();
    d = cast.getD();
    f = cast.getF();
}

Cast &Cast::operator=(const Cast &cast) {
    c = cast.getC();
    i = cast.getI();
    d = cast.getD();
    f = cast.getF();
    return *this;
}

Cast::Cast() : c(0), i(0), d(0.0), f(0.0f) {}

Cast::~Cast() {}

std::ostream &operator<<(std::ostream &os, const Cast &cast) {
    os << "c: " << cast.getC() << " i: " << cast.getI() << " d: " << cast.getD() << " f: " << cast.getF();
    return os;
}

void Cast::castChar(char *str, int a) {
    std::cout << "char: ";

    try
    {
        int num = std::stoi(str);
        if (num < 32 && num >= 0)
            std::cout << "NON PRINTABLE CHARACTERS" << std::endl;
        else if (num >= 32 && num < 128)
            std::cout  << "'" << static_cast<char>(a) << "'" << std::endl;
        else if (num >= 128 && num < 256)
            std::cout << "EXTENDED ASCII CHARACTERS" << std::endl;
        else
            std::cout << "impossible" << std::endl;
    }
    catch (std::exception)
    {
        if (!strcmp(str, ""))
            std::cout << "impossible" << std::endl;
        else if (strlen(str) > 1)
            std::cout << "impossible" << std::endl;
        else if (isprint(str[0]) && strlen(str) == 1)
            std::cout << "'" << str[0] << "'" << std::endl;
    }
}

void    Cast::castInt(char * str)
{
    std::cout << "int: ";
    try
    {
        int a = std::stoi(str);
            std::cout << a << std::endl;
    }
    catch (std::exception)
    {
        if (strlen(str) == 1)
        {
            std::cout << static_cast<int>(*str) << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }

}

void    Cast::castFloat(char *str, int b)
{
    std::cout << "float: ";
    try
    {
        float a = std::stof(str);
        std::cout << a;
        if (a == static_cast<float>(b))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    catch (std::exception)
    {
        if (strlen(str) == 1)
        {
            std::cout << static_cast<float>(*str) << ".0f" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
}

void    Cast::castDouble(char * str, int b)
{
    std::cout << "double: ";

    try {
        double	a = std::stod(str);
        std::cout << a;
        if (a == static_cast<double>(b))
            std::cout << ".0";
        std::cout << std::endl;
    }
    catch (std::exception)
    {
        if (strlen(str) == 1)
        {
            std::cout << static_cast<double>(*str) << ".0" << std::endl;
        }
        else
            std::cout << "impossible" << std::endl;
    }
}
