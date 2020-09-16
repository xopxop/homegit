/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:07:48 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 19:25:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
	{
		Sorcerer robert("Robert", "the Magnificent");

		Victim jim("Jim");
		Peon joe("Joe");

		std::cout << robert << jim << joe;
	
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	std::cout << "==================================" << std::endl;
	{
		Sorcerer robert("Robert", "the Magnificent");
		Sorcerer robertCopy(robert);
		
		Victim jim("Jim");
		Victim jimCopy(jim);
		
		Peon joe("Joe");
		Peon joeCopy(joe);
		
		std::cout << robertCopy << jimCopy << joeCopy;
	
		robertCopy.polymorph(jimCopy);
		robertCopy.polymorph(joeCopy);
	}
	return 0;
}
