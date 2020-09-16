/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:35:28 by dthan             #+#    #+#             */
/*   Updated: 2020/08/26 02:21:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::cout << "---------CREATING INSTANCE---------" << std::endl;
	FragTrap instance_1("Bob");
	FragTrap instance_2("Alice");
	FragTrap instance_3("Danny");
	FragTrap instance_4("Anni");
	FragTrap instance_5(instance_1);
	std::cout << "---------ATACK AND TAKING DAME---------" << std::endl;
	instance_1.meleeAttack(instance_2.getName());
	instance_2.takeDamage(30);
	instance_3.rangedAttack(instance_4.getName());
	instance_4.takeDamage(20);
	for (int i = 0 ; i < 6; i++)
	{
		instance_5.meleeAttack(instance_5.getName());
		instance_5.takeDamage(30);
	}
	std::cout << "---------USING VAULTHUNTER.EXE---------" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		instance_1.vaulthunter_dot_exe(instance_2.getName());
		instance_2.takeDamage(40);
	}
	std::cout << "---------REPARING---------" << std::endl;
	for (int i = 0; i < 7 ; i++)
		instance_5.beRepaired(20);
	instance_1.takeDamage(30);
	for (int i = 0; i < 7 ; i++)
		instance_1.beRepaired(30);
	std::cout << "---------DECONSTRUCTING INSTANCE-------" << std::endl;
	return (0);
}
