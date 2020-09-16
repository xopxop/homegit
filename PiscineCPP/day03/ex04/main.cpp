/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 01:35:28 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 18:31:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(int ac, char **av)
{
	std::cout << "---------CREATING FRAGTRAP---------" << std::endl;
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


	std::cout << "---------CREATING SCAVTRAP---------" << std::endl;
	ScavTrap instance_6("Bob");
	ScavTrap instance_7("Alice");
	ScavTrap instance_8("Danny");
	ScavTrap instance_9("Anni");
	ScavTrap instance_10(instance_6);
	std::cout << "---------ATACK AND TAKING DAME---------" << std::endl;
	instance_6.meleeAttack(instance_7.getName());
	instance_7.takeDamage(20);
	instance_8.rangedAttack(instance_9.getName());
	instance_9.takeDamage(15);
	for (int i = 0 ; i < 6; i++)
	{
		instance_10.meleeAttack(instance_10.getName());
		instance_10.takeDamage(20);
	}
	std::cout << "---------REPARING---------" << std::endl;
	for (int i = 0; i < 7 ; i++)
		instance_10.beRepaired(20);
	instance_6.takeDamage(20);
	for (int i = 0; i < 7 ; i++)
		instance_6.beRepaired(30);
	std::cout << "---------CHALLENGING---------" << std::endl;
	instance_6.challengeNewcomer(instance_7.getName());
	instance_7.challengeNewcomer(instance_8.getName());
	instance_8.challengeNewcomer(instance_9.getName());
	instance_9.challengeNewcomer(instance_10.getName());
	std::cout << "---------CREATING SCAPTRAP---------" << std::endl;
	ClapTrap instance_11;
	ClapTrap instance_12("Alice");
	ClapTrap instance_13("Danny");
	ClapTrap instance_14("Anni");
	ClapTrap instance_15(instance_11);
	std::cout << "---------ATACK AND TAKING DAME---------" << std::endl;
	instance_11.meleeAttack(instance_12.getName());
	instance_12.takeDamage(instance_11.getMeleeAttackDamage());
	instance_13.rangedAttack(instance_14.getName());
	instance_14.takeDamage(instance_13.getRangedAttackDamage());
	for (int i = 0 ; i < 6; i++)
	{
		instance_15.meleeAttack(instance_15.getName());
		instance_15.takeDamage(instance_15.getMeleeAttackDamage());
	}
	std::cout << "---------TEST INSTANCES-------" << std::endl;
	std::cout << instance_1 << std::endl;
	std::cout << instance_2 << std::endl;
	std::cout << instance_3 << std::endl;
	std::cout << instance_4 << std::endl;
	std::cout << instance_5 << std::endl;
	std::cout << instance_6 << std::endl;
	std::cout << instance_7 << std::endl;
	std::cout << instance_8 << std::endl;
	std::cout << instance_9 << std::endl;
	std::cout << instance_10 << std::endl;
	std::cout << instance_11 << std::endl;
	std::cout << instance_12 << std::endl;
	std::cout << instance_13 << std::endl;
	std::cout << instance_14 << std::endl;
	std::cout << instance_15 << std::endl;
	std::cout << "---------CREATING NINJATRAP---------" << std::endl;
	NinjaTrap instance_16;
	NinjaTrap instance_17("Bob");
	NinjaTrap instance_18(instance_17);
	std::cout << "---------TEST SHOESBOX-------" << std::endl;
	instance_16.ninjaShoebox(instance_2);
	instance_16.ninjaShoebox(instance_7);
	instance_16.ninjaShoebox(instance_17);
	std::cout << "---------DECONSTRUCTING INSTANCEs-------" << std::endl;
	return (0);
}
