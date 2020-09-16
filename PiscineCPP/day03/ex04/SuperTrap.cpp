/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 18:18:32 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 19:03:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"
#include <iostream>

int SuperTrap::_nbr = 0;

SuperTrap::SuperTrap(void) : FragTrap(), NinjaTrap()
{
	this->FragTrap::_hitPoints;
	this->FragTrap::_maxHitPoints;
	this->NinjaTrap::_energyPoints;
	this->NinjaTrap::_maxEnergyPoint;
	_level = 1;
	this->_name = "none";
	this->NinjaTrap::_meleeAttackDamage;
	this->FragTrap::_rangedAttackDamage;
	this->FragTrap::_armorDamageReduction = 0;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name) , NinjaTrap(name)
{
	this->FragTrap::_hitPoints;
	this->FragTrap::_maxHitPoints;
	this->NinjaTrap::_energyPoints;
	this->NinjaTrap::_maxEnergyPoint;
	_name = name;
	this->NinjaTrap::_meleeAttackDamage;
	this->FragTrap::_rangedAttackDamage;
	this->FragTrap::_armorDamageReduction = 0;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: This time it'll be awesome, I promise!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	*this = src;
	this->_nbr++;
	this->_nbrID = _nbr;
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: Recompiling my combat code!" << std::endl;
	return ;
}

SuperTrap::~SuperTrap(void)
{
	this->_nbr--;
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: Robot down!" << std::endl;
	return ;
}

void SuperTrap::rangedAttack(std::string const & target)
{
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: attacked " << target << " at range, causing " << this->_rangedAttackDamage << " points of damage !" << std::endl;
}

void SuperTrap::meleeAttack(std::string const & target)
{
	std::cout << "SuperTrap" << this->_nbrID << " [" << this->_name << "]: attacked " << target << ", causing " << this->_meleeAttackDamage << " points of damage !" << std::endl;
}

/*ostream*/
std::ostream & operator << (std::ostream & out, const SuperTrap & in)
{
	out << "SuperTrap" << in.getNumberID() << " [" << in.getName() << \
	"]: HP:" << in.getHitPoints() << "/" << in.getMaxHitPoints() \
	<< " SP:" << in.getEnergyPoints() << "/" << in.getMaxEnergyPoints();
	return (out);
}
