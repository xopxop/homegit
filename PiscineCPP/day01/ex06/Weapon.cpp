/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 12:45:37 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 12:45:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
	std::cout << "Weapon Constructor called!" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon Destructor called!" << std::endl;
}

std::string&    Weapon::getType(void) {
	return (this->_type);
}

void            Weapon::setType(std::string type) {
    this->_type = type;
}
