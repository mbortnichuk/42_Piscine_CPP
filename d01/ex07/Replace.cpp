/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:43:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 14:43:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

Replace::Replace(void) {
	this->s1 = "null";
	this->s2 = "null";
	this->fileName = "null.replace";
}

Replace::Replace(std::string s1, std::string s2, std::string fileName) {
	this->s1 = s1;
	this->s2 = s2;
	this->fileName = fileName;

	for (size_t i = 0; i < fileName.length(); ++i) {
		fileName[i] = toupper(fileName[i]);
	}
	this->createFileName = std::string(fileName + ".replace");
}

Replace::~Replace(void) {
	return ;
}

void Replace::setS1(std::string s) {
	this->s1 = s;
}
void Replace::setS2(std::string s) {
	this->s2 = s;
}
void Replace::setFileName(std::string fileName) {
	this->fileName = fileName;
}

std::string Replace::getS1(void) {
	return (this->s1);
}
std::string Replace::getS2(void) {
	return (this->s2);
}
std::string Replace::getFileName(void) {
	return (this->fileName);
}

std::string Replace::getCreateFileName(void) {
	return (this->createFileName);
}

// Validation

void 	Replace::validation(void) {
	if (this->s1.length() == 0 || this->s2.length() == 0) {
		std::cout << "empty string\n";
		std::exit(1);
	}
}

bool	Replace::replaceFile(void) {
	std::ifstream myFile(this->getFileName());
	if (myFile.is_open()) {
		std::string line;
		std::fstream file;
		file.open(this->getCreateFileName(), std::fstream::in | std::fstream::out | std::fstream::app);
		while (std::getline(myFile, line)) {
			while (1) {
				size_t i = line.find(this->getS1());
				if (i != std::string::npos) {
					line.replace(i, this->getS1().length(), this->getS2());
					for (size_t j = 0; j < i; j++) {
						file << line[j];
					}
					std::string tmp = this->getS2();
					for (size_t j = 0; j < tmp.length(); j++) {
						file << tmp[j];
					}
					line = &line[i + this->getS2().length()];
				}
				else {
					file << line << '\n';
					break ;
				}
			}
		}
		file.close();
		myFile.close();
		return (true);
	}
	return (false);
}
