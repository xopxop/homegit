/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 06:25:10 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 18:05:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include <iostream>

int NinjaTrap::_nbr = 0;

NinjaTrap::NinjaTrap(void)
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_name = "none";
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 50;
	this->_armorDamageReduction = 0;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name)
{
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 50;
	this->_armorDamageReduction = 0;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap(void)
{
	this->_nbr--;
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

void NinjaTrap::takeDamage(unsigned int amount)
{
	int realDamage;

	realDamage = amount - this->_armorDamageReduction;
	(realDamage <= 0) ? realDamage = 0 : 0;

	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: ";
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

void NinjaTrap::beRepaired(unsigned int amount)
{
	int recoveredHitPoint;
	int recoveredEnergyPoint;

	recoveredHitPoint = ((this->_maxHitPoints - this->_hitPoints) < amount) ? (this->_maxHitPoints - this->_hitPoints ) : amount;
	recoveredEnergyPoint = ((this->_maxEnergyPoint - this->_energyPoints) < amount) ? (this->_maxEnergyPoint - this->_energyPoints) : amount;
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: recovered " << recoveredHitPoint << " HP and " << recoveredEnergyPoint << " SP" << std::endl;
	this->_hitPoints += recoveredHitPoint;
	this->_energyPoints += recoveredEnergyPoint;
}

/*ninjaShoebox method*/
void NinjaTrap::ninjaShoebox(ClapTrap const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Hei CLAPTRAP- " << target.getNumberID() << " [" << target.getName() << "]" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Hei FR4G-TP" << target.getNumberID() << " [" << target.getName() << "]" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Hei CS4G-TP" << target.getNumberID() << " [" << target.getName() << "]" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::cout << "NinjaTrap" << this->_nbrID << " [" << this->_name << "]: Hei NINJATRAP-" << target.getNumberID() << " [" << target.getName() << "]" << std::endl;
}

/*ostream*/
std::ostream & operator << (std::ostream & out, const NinjaTrap & in)
{
	out << "NinjaTrap" << in.getNumberID() << " [" << in.getName() << \
	"]: HP:" << in.getHitPoints() << "/" << in.getMaxHitPoints() \
	<< " SP:" << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints();
	return (out);
}
