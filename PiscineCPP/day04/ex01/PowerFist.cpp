/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:18:51 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:24:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

/* Coplien's form */
PowerFist::PowerFist(void): AWeapon("Power Fist", 8 , 50) { }

PowerFist::PowerFist(PowerFist const & src)
{
	this->_name = src.getName();
	this->_ap = src.getAPCost();
	this->_damage = src.getDamage();
}

PowerFist::~PowerFist(void) { }

PowerFist & PowerFist::operator = (PowerFist const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

/* Method */
void PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
