/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:40:43 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 14:40:44 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace {
private:
	std::string input;
	std::string output;
public:
	Replace();
	Replace(std::string input, std::string output);
	void	replace(std::string s1, std::string s2);
	~Replace();
};

#endif
