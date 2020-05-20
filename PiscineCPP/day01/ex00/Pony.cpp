/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 00:59:14 by dthan             #+#    #+#             */
/*   Updated: 2020/05/01 00:59:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string nickname, unsigned int age, std::string color)
{
	this->_nickname = nickname;
	this->_age = age;
	this->_color = color;
	std::cout << "Constructor " << this->_nickname << std::endl;

	return ;
}

Pony::~Pony(void) {
	std::cout << "Deconstructor " << this-> _nickname <<  std::endl;
	return ;
}

std::string Pony::getNickname(void) const {
	return this->_nickname;
}

int			Pony::getAge(void) const {
	return this->_age;
}

std::string Pony::getColor(void) const {
	return this->_color;
}
