/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:49:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:49:54 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		std::string				_type;	
		unsigned int			xp_;

	public:
		AMateria(std::string const &type);
		virtual ~AMateria(void);
		AMateria(AMateria const &src);

		AMateria			&operator=(AMateria const &rhs);

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter const &target);

		std::string const	&getType() const;
		unsigned int		getXP() const;
};

#endif
