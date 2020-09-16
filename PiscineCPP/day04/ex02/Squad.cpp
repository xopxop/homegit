/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:10:41 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 08:30:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

int Squad::_numberOfUnits = 0;

/* Coplien's form */
Squad::Squad(void)
{
	_squad = NULL;
}

Squad::Squad(Squad const & src)
{
	_numberOfUnits++;
	*this = src;
}

Squad::~Squad(void)
{
	t_container *tmp;
	t_container *ptr;

	ptr = this->_squad;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		delete(tmp->unit);
		delete(tmp);
	}
}

Squad & Squad::operator = (Squad const & rhs)
{
	if (this != & rhs)
	{
		t_container *tmp;
		// destroy the this
		if (this->_squad != NULL)
		{
			while (this->_squad)
			{
				tmp = this->_squad;
				this->_squad = this->_squad->next;
				delete(tmp->unit);
				delete(tmp);
			}
		}
		if (rhs._squad != NULL)
		{
			t_container *ptr;

			ptr = rhs._squad;
			while (rhs._squad)
			{
				this->push(ptr->unit->clone());
				ptr = ptr->next;
			}
		}
	}
	return (*this);
}

/* method */
int Squad::getCount(void) const
{
	return this->_numberOfUnits;
}

ISpaceMarine* Squad::getUnit(int unitNumber) const
{
	int i;
	t_container *ptr;

	if (this->_squad == NULL)
		return NULL;
	i = -1;
	ptr = this->_squad;
	while (++i < _numberOfUnits)
	{
		if (i == unitNumber)
			return (ptr->unit);
		ptr = ptr->next;
	}
	return (NULL);
}

int Squad::push(ISpaceMarine* unit)
{
	t_container *new_unit = new t_container;
	t_container *ptr;

	new_unit->unit = unit;
	new_unit->next = NULL;
	ptr = this->_squad;
	if (this->_squad == NULL)
		this->_squad = new_unit;
	else
	{
		while (ptr->next)
		ptr = ptr->next;
		ptr->next = new_unit;
	}
	return ++_numberOfUnits;
}
