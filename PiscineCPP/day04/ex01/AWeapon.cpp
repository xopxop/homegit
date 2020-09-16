/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 22:30:55 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 02:44:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void) { }

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->_name = name;
	this->_ap = apcost;
	this->_damage = damage;
}

AWeapon::AWeapon(AWeapon const & src)
{
	this->_name = src.getName();
	this->_ap = src.getAPCost();
	this->_damage = src.getDamage();
}

AWeapon::~AWeapon(void) { }

AWeapon & AWeapon::operator = (AWeapon const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

/* Accessor */

std::string AWeapon::getName(void) const
{
	return (this->_name);
}

int	AWeapon::getAPCost(void) const
{
	return (this->_ap);
}

int AWeapon::getDamage(void) const
{
	return (this->_damage);
}
