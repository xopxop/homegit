/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 12:45:53 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 12:45:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
    std::cout << "HumanA Constructor called!" << std::endl;
}

HumanA::~HumanA(void) {
    std::cout << "HumanA Destructor called!" << std::endl;
}

void    HumanA::attack(void) {
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
