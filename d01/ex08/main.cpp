/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:13:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 15:13:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main()
{
	Human human;
	human.action("intimidatingShout", "intimidatingShout");
	human.action("rangedAttack", "rangedAttack");
	human.action("meleeAttack", "meleeAttack");
	return 0;
}
