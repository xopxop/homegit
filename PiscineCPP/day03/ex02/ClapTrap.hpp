/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 03:22:38 by dthan             #+#    #+#             */
/*   Updated: 2020/08/27 06:27:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <string>

class ClapTrap
{
	private:
		static int _nbr;
		int _nbrID;

	protected:
		int _hitPoints;
		int _maxHitPoints;
		int _energyPoints;
		int _maxEnergyPoint;
		int _level;
		std::string _name;
		int _meleeAttackDamage;
		int _rangedAttackDamage;
		int _armorDamageReduction;
		
	public:
		/*constructor and destructor and operator=*/
		ClapTrap(void);
		ClapTrap(std::string);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);
		ClapTrap & operator = (ClapTrap const & rhs);
		/*methods*/
		virtual void rangedAttack(std::string const & target);
		virtual void meleeAttack(std::string const & target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
		/*accessor*/
		int getHitPoints(void) const;
		int getMaxHitPoints(void) const;
		int getEnergyPoints(void) const;
		int getMaxEnergyPoints(void) const;
		int getLevel(void) const;
		std::string getName(void) const;
		int getMeleeAttackDamage(void) const;
		int getRangedAttackDamage(void) const;
		int getArmorDamageReduction(void) const;
		int getNumberID(void) const;
};

std::ostream & operator << (std::ostream & out, const ClapTrap & in);

#endif