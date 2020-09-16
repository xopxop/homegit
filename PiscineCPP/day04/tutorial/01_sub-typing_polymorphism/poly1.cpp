/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 04:03:47 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 01:11:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Character
{
	public:
		virtual void sayHello(std::string const & target);
};

class Warrior : public Character
{
	public:
		virtual void sayHello(std::string const & target);
};

class Cat
{
	//[...]
};

void Character::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void Warrior::sayHello(std::string const & target)
{
	std::cout << "F*** off " << target << ", I don't like you !" << std::endl;
}

int main()
{
	//This is OK, obviously, Warrior IS a Warrior
	Warrior*	a = new Warrior();

	//This is also OK because Warrior IS a Character
	Character*	b = new Warrior();

	//This would NOT be ok because Character IS NOT a Warrior
	//(Although they ARE related, and W IS-A C, the reverse is untrue)
	//Warrior*	c = new Character();

	//This would NOT be ok either because Cat IS NOT a Character
	//(They are not even related)
	//Character*	d = new Cat();

	a->sayHello("student");

	b->sayHello("student");
}
