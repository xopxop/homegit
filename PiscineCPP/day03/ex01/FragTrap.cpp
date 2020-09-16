/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:46:50 by dthan             #+#    #+#             */
/*   Updated: 2020/08/26 03:16:24 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int FragTrap::_numIst = 0;

FragTrap::FragTrap(std::string name) : _hitPoints(100), _maxHitPoints(100), \
_energyPoints(100), _maxEnergyPoint(100), _level(1), _meleeAttackDamage(30), \
_rangedAttackDamage(20), _armorDamageReduction(5)
{
	this->_name = name;
	this->_numIst++;
	this->_ownIst = _numIst;
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	this->_numIst++;
	this->_ownIst = _numIst;
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	this->_numIst--;
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int realDamage;

	realDamage = amount - this->_armorDamageReduction;
	(realDamage <= 0) ? realDamage = 0 : 0;

	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: ";
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

void FragTrap::beRepaired(unsigned int amount)
{
	int recoveredHitPoint;
	int recoveredEnergyPoint;

	recoveredHitPoint = ((this->_maxHitPoints - this->_hitPoints) < amount) ? (this->_maxHitPoints - this->_hitPoints ) : amount;
	recoveredEnergyPoint = ((this->_maxEnergyPoint - this->_energyPoints) < amount) ? (this->_maxEnergyPoint - this->_energyPoints) : amount;
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: recovered " << recoveredHitPoint << " HP and " << recoveredEnergyPoint << " SP" << std::endl;
	this->_hitPoints += recoveredHitPoint;
	this->_energyPoints += recoveredEnergyPoint;
}

std::string FragTrap::_vaulthunter_attacks[5]
{
	"Defragmenting!",
	"It's about to get magical!",
	"Let's get this party started!",
	"Hey everybody, check out my package!",
	"F to the R to the 4 to the G to the WHAAT!"
};

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]" << " out of SP" << std::endl;
		return ;
	}
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: activating VaultHunter.EXE" << std::endl;
	std::cout << "FR4G-TP" << this->_ownIst << " [" << this->_name << "]: " << FragTrap::_vaulthunter_attacks[std::rand() % 5] << std::endl;
	this->_energyPoints -= 25;
}

std::string FragTrap::getName(void)
{
	return this->_name;
}
