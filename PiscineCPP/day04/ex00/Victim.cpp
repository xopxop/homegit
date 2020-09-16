/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:23:37 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 19:16:58 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void) { }

Victim::Victim(std::string name)
{
	this->_name =  name;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	this->_name = src._name;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
}

Victim & Victim::operator = (Victim const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}

std::ostream & operator << (std::ostream & o, const Victim & i)
{
	o << "I'm " << i.getName() << " and I like otters !" << std::endl;
	return (o);
}

std::string Victim::getName(void) const
{
	return (this->_name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}
