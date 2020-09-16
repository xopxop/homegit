/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:29:24 by dthan             #+#    #+#             */
/*   Updated: 2020/08/25 18:32:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Quadruped //Can access name, run() and legs
{
	private:
		std::string name; //Only accessible from an Quadruped object
	protected:
		Leg			Legs[4]; //Accessible from an Quadruped or derived object
	public:
		void		run();	//Accessible from wherever
};

class Dog : public Quadruped //Can access run() and legs
{

};

int main() //Can only access run()
{

}