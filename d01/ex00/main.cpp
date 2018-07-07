/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:56:50 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/14 14:56:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony ponyOnTheStack(std::string name, std::string breed, int age) {
	return Pony(name, breed, age);
}

Pony *ponyOnTheHeap(std::string name, std::string breed, int age) {
	return new Pony(name, breed, age);
}

int main(void) {
	Pony stackPony = ponyOnTheStack("Stack Pony", "Brown horse", 3);
	Pony *heapPony = ponyOnTheHeap("Heap Pony", "Black horse", 4);
	delete heapPony;
	return 0;
}
