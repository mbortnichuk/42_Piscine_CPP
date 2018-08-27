/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:40:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/17 17:40:52 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <stdlib.h>

# include "Playground.hpp"
# include "Champ.hpp"
# include "Object.hpp"
# include "Enemy.hpp"
# include "Jet.hpp"
# include "Bullet.hpp"

void printScore(Playground & pl);
void printLogo(Playground pl);
void printDie(Playground & pl);
int difficultyMode(int i);
void getStarted(int i, Playground & pl);
void printMenu(Playground & pl);
void game(void);


# define KEY_ESC 27



#endif
