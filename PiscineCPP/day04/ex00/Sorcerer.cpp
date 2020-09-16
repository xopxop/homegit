/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 05:47:31 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 19:13:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) { }

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->_name =  name;
	this->_title = title;
	std::cout << this->_name << ", " << this->_title << ", is born !" <<std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	this->_name = src._name;
	this->_title = src._title;
	std::cout << this->_name << ", " << this->_title << ", is born !" <<std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" <<std::endl;
}

Sorcerer & Sorcerer::operator = (Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_title = rhs._title;
	}
	return (*this);
}

std::ostream & operator << (std::ostream & o, const Sorcerer & i)
{
	o << "I am " << i.getName() << ", " << i.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}

std::string Sorcerer::getName(void) const
{
	return (this->_name);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void Sorcerer::polymorph(Victim const & target) const
{
	target.getPolymorphed();
}
