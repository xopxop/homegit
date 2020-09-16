/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:58:44 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:39:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* Coplien's form */
Character::Character(std::string const & name)
{
	this->_name = name;
	this->_ap = MAX_AP;
	this->_weapon = NULL;
}

Character::Character(Character const & src)
{
	this->_name = src.getName();
}

Character::~Character(void) { }

Character & Character::operator = (Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}

/* accessor */
std::string Character::getName(void) const
{
	return this->_name;
}

int Character::getAP(void) const
{
	return this->_ap;
}

AWeapon * Character::getWeapon(void) const
{
	return this->_weapon;
}

/* methods */
void Character::recoverAP(void)
{
	if (this->_ap = MAX_AP)
		return ;
	this->_ap += 10;
	if (this->_ap > MAX_AP)
		this->_ap = MAX_AP;
}

void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void Character::attack(Enemy *target)
{
	if (this->_weapon == NULL)
		return ;
	if (this->_ap < this->_weapon->getAPCost())
		return ;
	std::cout << this->_name << " attacks " << target->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	this->_ap -= this->_weapon->getAPCost();
	target->takeDamage(this->_weapon->getDamage());
}

std::ostream & operator << (std::ostream & o, Character const & i)
{
	if (i.getWeapon() == NULL)
		o << i.getName() << " has " << i.getAP() << " AP and is unarmed" << std::endl;
	else
		o << i.getName() << " has " << i.getAP() << " AP and wields a " << i.getWeapon()->getName() << std::endl;
	return (o);
}
