/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:31:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 16:31:54 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

Logger::Logger(): nameOutputFile("logFile.txt") {
}

Logger::~Logger() {
}

void		Logger::logToConsole(std::string const & target)
{
	std::cout << target << std::endl;
}

void		Logger::logToFile(std::string const & target)
{
	std::ofstream output(nameOutputFile, std::ios::app);
    output << target << std::endl;
    output.close();
}

std::string	Logger::makeLogEntry(std::string message) {
	time_t now = time(0);
	char* date = ctime(&now);
	std::string str = date;
	str.erase(str.end()-1, str.end());
	message = str + ": " + message;

	return message;
}

void		Logger::log(std::string const & dest, std::string const & message)
{
	typedef void (Logger::*FUN)(std::string const & message);

	FUN fun[] = {&Logger::logToFile, &Logger::logToConsole};
	std::string name[] = {"logToFile", "logToConsole"};
	for(int i = 0; i < 2; i++)
	{
		if(name[i] == dest)
			(this->*fun[i])(makeLogEntry(message));
    }
}
