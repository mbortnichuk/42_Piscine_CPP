/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:41:07 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/13 19:41:09 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace::std;

int main(int ac, char **av) {
	int i = 1;
	int j;

	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		while (i < ac) {
			j = 0;
			while (av[i][j]) {
				av[i][j] = toupper(av[i][j]);
				j++;
			}
			cout << av[i];
			i++;
		}
		cout << "\n";
	}
	return 0;
}
