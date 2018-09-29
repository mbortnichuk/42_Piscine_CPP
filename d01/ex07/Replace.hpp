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
#include <iostream>
#include <fstream>

class 	Replace {
	private:
		std::string fileName;
		std::string createFileName;
		std::string s1;
		std::string s2;
	public:
		Replace(void);
		Replace(std::string s1, std::string s2, std::string fileName);
		~Replace(void);

		void setS1(std::string s);
		void setS2(std::string s);
		void setFileName(std::string fileName);
		std::string getS1(void);
		std::string getS2(void);
		std::string getFileName(void);
		std::string getCreateFileName(void);
		bool		replaceFile(void);
		void 		validation(void);
};

#endif
