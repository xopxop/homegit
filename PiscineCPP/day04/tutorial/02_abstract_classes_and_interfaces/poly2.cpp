/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 05:13:04 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 05:31:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ACharacter
{
	public:
		virtual void	attack(std::string const & tartget) = 0;
		void			sayHello(std::string const & target);
};

class Warrior : public ACharacter
{
	public:
		virtual void	attack(std::string const & target);
};

void ACharacter::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void Warrior::attack(std::string const & target)
{
	std::cout << "*attacks " << target << " with a sword" << std::endl;
}

// class IcoffeeMaker
// {
// 	public:
// 		virtual	void		fillWaterTank(IWaterSource * src) = 0;
// 		virtual ICoffee*	makeCoffee(std::string const & type) = 0;
// };

int main()
{
	ACharacter*		a = new Warrior();
	//This would NOT be ok because ACharacter is abstract
	// ACharacter*	b = new ACharacter();

	a->sayHello("students");
	a->attack("roger");
}

