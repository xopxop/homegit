/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 02:38:57 by dthan             #+#    #+#             */
/*   Updated: 2020/08/26 03:20:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int ScavTrap::_numIst = 0;

ScavTrap::ScavTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), \
_energyPoints(50), _maxEnergyPoint(50), _level(1), _meleeAttackDamage(20), \
_rangedAttackDamage(15), _armorDamageReduction(3)
{
	this->_name = name;
	this->_numIst++;
	this->_ownIst = _numIst;
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	this->_numIst++;
	this->_ownIst = _numIst;
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	this->_numIst--;
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	int realDamage;

	realDamage = amount - this->_armorDamageReduction;
	(realDamage <= 0) ? realDamage = 0 : 0;

	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: ";
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

void ScavTrap::beRepaired(unsigned int amount)
{
	int recoveredHitPoint;
	int recoveredEnergyPoint;

	recoveredHitPoint = ((this->_maxHitPoints - this->_hitPoints) < amount) ? (this->_maxHitPoints - this->_hitPoints ) : amount;
	recoveredEnergyPoint = ((this->_maxEnergyPoint - this->_energyPoints) < amount) ? (this->_maxEnergyPoint - this->_energyPoints) : amount;
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: recovered " << recoveredHitPoint << " HP and " << recoveredEnergyPoint << " SP" << std::endl;
	this->_hitPoints += recoveredHitPoint;
	this->_energyPoints += recoveredEnergyPoint;
}

std::string ScavTrap::_setOfChallenges[5]
{
	"Hot-Pepper",
	"Mannequin",
	"Try Not To Laugh",
	"Bottle-Flipping",
	"Choking/Fainting/Pass-Out"
};

void ScavTrap::challengeNewcomer(std::string const & target)
{
	std::cout << "CS4G-TP" << this->_ownIst << " [" << this->_name << "]: challenged " << target << " with " << ScavTrap::_setOfChallenges[std::rand() % 5] << " challenge" << std::endl;
}

std::string ScavTrap::getName(void)
{
	return this->_name;
}
