/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:31:57 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 16:31:58 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <ctime>

class Logger {
private:
	void	logToConsole(std::string const & target);
	void	logToFile(std::string const & target);
	std::string makeLogEntry(std::string message);
	std::string 	nameOutputFile;
public:
	Logger();
	void	log(std::string const & dest, std::string const & message);
	~Logger();
};

#endif
