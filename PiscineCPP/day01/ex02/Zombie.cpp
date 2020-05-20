/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zomebie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:12:46 by dthan             #+#    #+#             */
/*   Updated: 2020/05/02 16:12:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string typez, std::string namez) : type(typez), name(namez) {
	this->announce();
}

Zombie::~Zombie(void) {
	std::cout << "<" << this->name << " (" <<
	this->type << ")> has been shoot" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << "<" << this->name << " (" <<
	this->type << ")> Braiiiiiiinnnssss..." << std::endl;
}
