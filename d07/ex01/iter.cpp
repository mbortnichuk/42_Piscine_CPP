/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:04:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/28 14:04:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void iter(T *a, size_t s, void (*f)(T)) {
	for (size_t i = 0; i < s; i++) {
		f(a[i]);
	}
}

template<typename T>
void check(T t) {
	std::cout << t << std::endl;
}

int main(void) {
	char str[] = "helloworld!";
	int arr[] = {1, 12, 432, 65, 33, 91, 19};
	float fp[] = {1.1, 123.321, 4.6, 23.5, 9.11, 6.76};
	std::string s[] = {"blablabla", "lol", "ololo"};
	::iter(str, 11, ::check);
	::iter(arr, 7, ::check);
	::iter(fp, 6, ::check);
	::iter(s, 3, ::check);

	return 0;
}
