/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:34:33 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 17:54:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") { }

Cure::Cure(Cure const & rhs)
{
	*this = rhs;
}

Cure & Cure::operator = (Cure const & rhs)
{
	if (this != &rhs)
	{
		this->setXP(rhs.getXP());
	}
	return (*this);
}

Cure::~Cure(void) { }

AMateria* Cure::clone(void) const
{
	return (AMateria*) new Cure();
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
