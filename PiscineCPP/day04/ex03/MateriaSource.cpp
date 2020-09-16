/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:05:40 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 01:51:36 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < _maxSource ; i++)
		this->_m[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != & rhs)
	{

	}
	return *this;
}

MateriaSource::~MateriaSource(void) { }

void MateriaSource::learnMateria(AMateria *m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < _maxSource; i++)
	{
		if (this->_m[i] == NULL)
		{
			this->_m[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _maxSource; i++)
	{
		if (this->_m[i] != NULL)
			if(this->_m[i]->getType() == type)
				return this->_m[i]->clone();
	}
	return NULL;
}
