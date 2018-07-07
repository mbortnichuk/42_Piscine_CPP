/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:29:55 by mbortnic          #+#    #+#             */
/*   Updated: 2018/06/18 16:29:56 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int		main(void)
{
	Logger logger;
	
	logger.log("logToConsole", "logToConsole");
	logger.log("logToFile", "logToFile");
	
	return 0;
}
