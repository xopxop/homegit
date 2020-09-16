/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 03:22:36 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 05:20:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int ClapTrap::_nbr = 0;

/* Constructor & Destructor */
ClapTrap::ClapTrap(void): _name("none"), _hitPoints(100), _maxHitPoints(100), \
_energyPoints(100), _maxEnergyPoint(100), _level(1), _meleeAttackDamage(0), \
_rangedAttackDamage(0), _armorDamageReduction(0)
{
	_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: Let's get this party started!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(100), _maxHitPoints(100), \
_energyPoints(100), _maxEnergyPoint(100), _level(1), _meleeAttackDamage(0), \
_rangedAttackDamage(0), _armorDamageReduction(0)
{
	_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	_nbr--;
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_maxHitPoints = rhs._maxHitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_maxEnergyPoint = rhs._maxEnergyPoint;
		this->_level = rhs._level;
		this->_name = rhs._name;
		this->_meleeAttackDamage = rhs._meleeAttackDamage;
		this->_rangedAttackDamage = rhs._rangedAttackDamage;
		this->_armorDamageReduction = rhs._armorDamageReduction;
	}
	return (*this);
}

/* ACCESSOR */
int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getMaxHitPoints(void) const
{
	return this->_maxHitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoint;
}

int ClapTrap::getLevel(void) const
{
	return this->_level;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::getMeleeAttackDamage(void) const
{
	return this->_meleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage(void) const
{
	return this->_rangedAttackDamage;
}

int ClapTrap::getArmorDamageReduction(void) const
{
	return this->_armorDamageReduction;
}

int ClapTrap::getNumberID(void) const
{
	return this->_nbrID;
}

/* Method */

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int realDamage;

	realDamage = amount - this->_armorDamageReduction;
	(realDamage <= 0) ? realDamage = 0 : 0;

	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: ";
	if (this->_hitPoints == 0)
		std::cout << "is already dead";
	else
	{
		if (this->_hitPoints <= realDamage)
		{
			realDamage = this->_hitPoints;
			std::cout << "took " << realDamage << " damage and now dead";
		}
		else
			std::cout << "took " << realDamage << " damage";
	}
	std::cout << std::endl;
	_hitPoints = (realDamage < _hitPoints) ? (_hitPoints - realDamage) : 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int recoveredHitPoint;
	int recoveredEnergyPoint;

	recoveredHitPoint = ((this->_maxHitPoints - this->_hitPoints) < amount) ? (this->_maxHitPoints - this->_hitPoints ) : amount;
	recoveredEnergyPoint = ((this->_maxEnergyPoint - this->_energyPoints) < amount) ? (this->_maxEnergyPoint - this->_energyPoints) : amount;
	std::cout << "CLAPTRAP-" << this->_nbrID << " [" << this->_name << "]: recovered " << recoveredHitPoint << " HP and " << recoveredEnergyPoint << " SP" << std::endl;
	this->_hitPoints += recoveredHitPoint;
	this->_energyPoints += recoveredEnergyPoint;
}

/* OSTREAM */
std::ostream & operator << (std::ostream & out, const ClapTrap & in)
{
	out << "CLAPTRAP-" << in.getNumberID() << " [" << in.getName() << \
	"]: HP:" << in.getHitPoints() << "/" << in.getMaxHitPoints() \
	<< " SP:" << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints();
	return (out);
}
