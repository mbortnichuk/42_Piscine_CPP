/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:57:35 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/29 12:57:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interface.class.hpp"

int main(void) {
	Interface *inter = new Interface;
	inter->start();
	delete inter;

	return 0;
}
