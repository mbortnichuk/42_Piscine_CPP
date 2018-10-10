/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:31:26 by mbortnic          #+#    #+#             */
/*   Updated: 2018/07/17 17:39:54 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template<typename T>
void easyfind(T container, int needle) {
	typename T::iterator it;

	it = find(container.begin(), container.end(), needle);
	if (it != container.end())
		std::cout << "Element has been found in my container: " << *it << std::endl;
	else
		throw std::exception();
}

#endif
