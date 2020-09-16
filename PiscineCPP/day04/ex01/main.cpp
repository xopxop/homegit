/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 01:58:55 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:39:23 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"

int main()
{
	{
		Character* zaz = new Character("zaz");
		std::cout << *zaz;

		Enemy* b = new RadScorpion();

		AWeapon *pr = new PlasmaRifle();
		AWeapon *pf = new PowerFist();

		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);
		
		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
	}
	std::cout << "===================================" << std::endl;
	{
		Character* zaz = new Character("zaz");
		std::cout << *zaz;

		Enemy* b = new SuperMutant();

		AWeapon *pr = new PlasmaRifle();
		AWeapon *pf = new PowerFist();

		zaz->equip(pr);
		std::cout << *zaz;
		zaz->equip(pf);
		zaz->attack(b);
		std::cout << *zaz;
		zaz->equip(pr);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
		zaz->attack(b);
		std::cout << *zaz;
	}
	return (0);
}
