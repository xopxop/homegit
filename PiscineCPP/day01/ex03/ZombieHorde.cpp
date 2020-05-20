/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 08:54:45 by dthan             #+#    #+#             */
/*   Updated: 2020/05/08 08:54:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int num) {
	if (num > 0) {
		std::cout << "A horde of " << num << " objects have been created!" << std::endl;
		this->horde = new Zombie[num];
		this->num = num;
		for (int i = 0; i < num; i++) {
			this->horde[i].name = this->randomName();
			this->horde[i].type = this->randomType();
		}
	}
	else
		std::cout << "Constructor failed!" << std::endl;
}

ZombieHorde::~ZombieHorde(void) {
	std::cout << "Destructor called" << std::endl;
	if (num > 0)
		delete [] this->horde;
}

void ZombieHorde::announce(void) {
	for (int i = 0; i < num; i++)
		this->horde[i].announce();
}

std::string ZombieHorde::randomName(void) {
	int i;
	int nameNb;
	std::string names[] = {"Keira", "Bonnie", "Tabitha", "Katherine", "Josie"};

	nameNb = 5;
	i = rand() % nameNb;
	return (names[i]);
}

std::string ZombieHorde::randomType(void) {
	int i;
	int typeNb;
	std::string types[] = {"Common Infected", "Uncommon Infected", "Boomer", "Jockey", "Smoker", "Charger", "Hunter", "Spitter", "Tank", "Witch"};

	typeNb = 10;
	i = rand() % typeNb;
	return (types[i]);
}
