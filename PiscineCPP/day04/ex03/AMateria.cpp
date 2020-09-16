/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:05:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 18:02:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*=========================================*/
AMateria::AMateria(void) { }

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	this->xp_ = 0;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria & AMateria::operator = (AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->setXP(rhs.getXP());
		// type here too
	}
	return (*this);
}

AMateria::~AMateria(void) { }

/*=========================================*/
void AMateria::setXP(unsigned int xp)
{
	this->xp_ = xp;
}

std::string const & AMateria::getType(void) const
{
	return this->_type;
}

unsigned int AMateria::getXP() const
{
	return this->xp_;
}

/*=========================================*/
void AMateria::use(ICharacter& target)
{
	(void)target;
	this->xp_ += 10;
}
