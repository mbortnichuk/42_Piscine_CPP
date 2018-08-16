/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:51:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/08/16 11:51:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		int					_materia_count;
		AMateria			*_materias[4];

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(MateriaSource const &src);

		MateriaSource		&operator=(MateriaSource const &rhs);

		void				learnMateria(AMateria *materia);
		AMateria			*createMateria(std::string const &type);
};

#endif
