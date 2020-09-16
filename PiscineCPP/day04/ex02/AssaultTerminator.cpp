/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:44:05 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:21:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
/* Coplien's form */
AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teloports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
	std::cout << "* teloports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back ..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator = (AssaultTerminator const & rhs)
{
	(void)rhs;
	return (*this);
}

/* methods */
ISpaceMarine* AssaultTerminator::clone(void) const
{
	// ISpaceMarine* copy = new AssaultTerminator();
	// return copy;
	return (ISpaceMarine*) new AssaultTerminator();
}

void AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

std::ostream & operator << (std::ostream & o, AssaultTerminator const & i)
{
	o << "Assault Terminator!!!" << std::endl;
	return o;
}
