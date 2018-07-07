/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 20:44:35 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/15 20:44:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class Human {
private:
	const Brain brain;
public:
	Human();
	std::string identify();
	Brain& getBrain();
	~Human() {
	};
};

#endif
