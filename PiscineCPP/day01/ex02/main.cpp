/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:13:14 by dthan             #+#    #+#             */
/*   Updated: 2020/05/02 16:13:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.Event.hpp"

int main() {
	Zombie Buckky("Boomer", "Buckky");
	ZombieEvents event;
	ZombieEvents random;

	event.newZombie("Peter Pan");
	event.setZombieType("Hunter");
	event.newZombie("Peter Pan");
	event.setZombieType("Smoker");
	random.setZombieType("Spliter");
	random.randomChump();
	std::cout << "Exterminating Buckky (on the Stack), Peter Pan (on the Heap), "
	<< random.ptr->name << "(on the Heap)" << std::endl;
}
