/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:58:46 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 01:54:54 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
# include <iostream>
# include <ostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

# define MAX_AP 40

class Character
{
	private:
		std::string _name;
		int			_ap;
		AWeapon		*_weapon;
	public:
		/* Coplien's form */
		Character(std::string const & name);
		Character(Character const & src);
		~Character(void);
		Character & operator = (Character const & rhs);
		/* accessor */
		std::string getName(void) const;
		int			getAP(void) const;
		AWeapon		*getWeapon(void) const;
		/* methods */
		void recoverAP(void);
		void equip(AWeapon*);
		void attack(Enemy*);
};

std::ostream & operator << (std::ostream & o, Character const & i);

#endif
