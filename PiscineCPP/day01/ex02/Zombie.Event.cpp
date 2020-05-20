/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zomebie.Event.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:13:06 by dthan             #+#    #+#             */
/*   Updated: 2020/05/02 16:13:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.Event.hpp"

ZombieEvents::ZombieEvents(void) {
	this->ptr = NULL;
	std::cout << "Event created" << std::endl;
}

ZombieEvents::~ZombieEvents(void) {
	std::cout << "Event Destroyed" << std::endl;
	if (this->ptr)
		this->killZombie();
}

void	ZombieEvents::killZombie(void) {
	delete this->ptr;
}

void ZombieEvents::setZombieType(std::string typez) {
	if (this->ptr == NULL)
		this->typez = typez;
	else {
		this->typez = typez;
		this->ptr->type = this->typez;
		this->ptr->announce();
	}
}

Zombie* ZombieEvents::newZombie(std::string name) {
    if (this->typez.empty()) {
        std::cout << "Please use function setZombieType() first" << std::endl;
        return (NULL);
    }
	this->ptr = new Zombie(this->typez, name);
    return (this->ptr);
}

Zombie* ZombieEvents::randomChump(void) {
	srand(time(0));
	std::string name;

	switch (rand() % 5 + 1) {
	case 1: name = "Keira";
			break;
	case 2: name = "Bonnie";
			break;
	case 3: name = "Tabitha";
			break;
	case 4: name = "Katherine";
			break;
	case 5: name = "Josie";
			break;	
	default:
			break;
	}
	if (this->ptr)
		this->killZombie();
	return (this->newZombie(name));
}

