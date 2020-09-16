/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:29:53 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:21:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
/* Coplien's form */
TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	*this = src;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine & TacticalMarine::operator = (TacticalMarine const & rhs)
{
	(void)rhs;
	return (*this);
}

/* methods */
ISpaceMarine* TacticalMarine::clone(void) const
{
	// ISpaceMarine* copy = new TacticalMarine();
	// return copy;
	return (ISpaceMarine*) new TacticalMarine();
}

void TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

std::ostream & operator << (std::ostream & o, TacticalMarine const & i)
{
	(void)i;
	o << "Tactical Marine!!!" << std::endl;
	return o;
}
