/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:37:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 12:37:44 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.struct.hpp"

void	*serialize(void) {
	const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand(time(0));

    struct Data  * data = new struct Data;
   	data->n = alphanum[std::rand() % 10];
    
    char forS1[9];
    char forS2[9];
    forS1[8] = '\0';
    forS2[8] = '\0';

    for (int i = 0; i < 8; i++)
    {
    	forS1[i] = alphanum[std::rand() % 62];
    	forS2[i] = alphanum[std::rand() % 62];
    }
    data->s1 = std::string(forS1);
    data->s2 = std::string(forS2);

	std::cout << "******** start ********" << std::endl; 
	std::cout << data->s1 << std::endl;
    std::cout << data->n << std::endl;
    std::cout << data->s2 << std::endl;

    return reinterpret_cast<void *>(data);
}

Data *deserialize(void * raw) {
	return reinterpret_cast<Data *>(raw);
}

int 	main() {
	struct Data * data;

	data = deserialize(serialize());
	std::cout << "******** result ********" << std::endl; 
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;

	return 0;
}
