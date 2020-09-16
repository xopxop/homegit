/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:03:11 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 01:15:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		Character(void);
		std::string _name;
		static const int _maxInventory = 4;
		AMateria* inventory[_maxInventory];
	
	public:
		Character(std::string name);
		Character(Character const & src);
		Character & operator = (Character const & rhs);
		~Character(void);

		std::string const & getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);
};

#endif
