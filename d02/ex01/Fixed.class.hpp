/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:28:58 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 19:28:59 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <cmath>
# include <iostream>

class Fixed {
private:
	int fixPoint;
	static const int bits = 8;
public:
	Fixed();
	Fixed(Fixed & a);
	Fixed(const Fixed & a);
	Fixed(const int a);
	Fixed(const float a);
	int toInt(void)const;
	float toFloat(void)const;
	~Fixed();
	int getRawBits(void)const;
	void setRawBits(int const raw);
	Fixed& operator = (Fixed const & a);
};

std::ostream& operator << (std::ostream& os, Fixed const& a);

#endif
