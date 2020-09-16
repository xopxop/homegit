/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 22:50:53 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:15:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

/* Coplien's form */
PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5 , 21) { }

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
	// this->_name = src.getName();
	// this->_ap = src.getAPCost();
	// this->_damage = src.getDamage();
	*this = src;
}

PlasmaRifle::~PlasmaRifle(void) { }

PlasmaRifle & PlasmaRifle::operator = (PlasmaRifle const & rhs)
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
void PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
