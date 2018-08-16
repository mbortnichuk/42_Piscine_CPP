/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:32:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 12:32:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cast_HPP
# define Cast_HPP

# include <ostream>

class Cast
{
private:
    char c;
    int i;
    double d;
    float f;

public:
    char        getC() const;
    int         getI() const;
    double      getD() const;
    float       getF() const;

    void        setC(char c);
    void        setI(int i);
    void        setD(double d);
    void        setF(float f);

    Cast(const Cast & cast);

    Cast();

    Cast& operator=(const Cast& cast);

    void    castChar(char * str, int);
    void    castInt(char *);
    void    castFloat(char*, int);
    void    castDouble(char *, int);



    ~Cast();

};

std::ostream &operator<<(std::ostream &os, const Cast &cast);

#endif
