/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 12:46:21 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 12:46:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    std::cout << "HumanB Constructor called!" << std::endl;
}

HumanB::~HumanB(void) {
    std::cout << "HumanB Destructor called!" << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}

void    HumanB::attack(void) {
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
