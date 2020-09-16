/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:54:42 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 17:55:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") { }

Ice::Ice(Ice const & rhs)
{
	*this = rhs;
}

Ice & Ice::operator = (Ice const & rhs)
{
	if (this != &rhs)
	{
		this->setXP(rhs.getXP());
	}
	return (*this);
}

Ice::~Ice(void) { }

AMateria* Ice::clone(void) const
{
	return (AMateria*) new Ice();
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
