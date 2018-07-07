/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:54:20 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 18:54:21 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed {
private:
	int fixPoint;
	static const int bits = 8;
public:
	Fixed();
	Fixed(Fixed & a);
	~Fixed();
	int getRawBits(void)const;
	void	setRawBits(int const raw);
	Fixed& operator = (Fixed&);
};

#endif
