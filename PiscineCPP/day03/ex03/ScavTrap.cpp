/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 02:38:57 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 05:54:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int ScavTrap::_nbr = 0;

ScavTrap::ScavTrap(void)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_name = "none";
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	this->_nbr--;
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	int realDamage;

	realDamage = amount - this->_armorDamageReduction;
	(realDamage <= 0) ? realDamage = 0 : 0;

	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: ";
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
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: recovered " << recoveredHitPoint << " HP and " << recoveredEnergyPoint << " SP" << std::endl;
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
	std::cout << "CS4G-TP" << this->_nbrID << " [" << this->_name << "]: challenged " << target << " with " << ScavTrap::_setOfChallenges[std::rand() % 5] << " challenge" << std::endl;
}

std::ostream & operator << (std::ostream & out, const ScavTrap & in)
{
	out << "CS4G-TP" << in.getNumberID() << " [" << in.getName() << \
	"]: HP:" << in.getHitPoints() << "/" << in.getMaxHitPoints() \
	<< " SP:" << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints();
	return (out);
}
