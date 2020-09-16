/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:02:04 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 00:14:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int	_maxSource = 4;
		AMateria*			_m[_maxSource];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		MateriaSource & operator=(MateriaSource const & rhs);
		~MateriaSource(void);

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif
