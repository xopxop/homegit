/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:23:03 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 01:17:05 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	for (int i = 0; i < _maxInventory; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->_name = name;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character & Character::operator= (Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		for (int i = 0; i < _maxInventory; i++)
		{
			if (inventory[i])
				delete (inventory[i]);
			inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < _maxInventory; i++)
		if (inventory[i])
			delete (inventory[i]);
}

std::string const & Character::getName(void) const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
		return ;

	for(int i = 0; i < _maxInventory; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= _maxInventory)
		return ;
	if (this->inventory[idx] != NULL)
		this->inventory[idx] == NULL;
	if (idx != _maxInventory - 1)
	{
		if (this->inventory[idx + 1] != NULL)
		{
			for (int i = idx + 1; i < _maxInventory; i++)
			{
				this->inventory[i - 1] = this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
	}
}

void Character::use(int idx, ICharacter & target)
{
	if (idx < 0 || idx >= _maxInventory)
		return ;
	if (this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
