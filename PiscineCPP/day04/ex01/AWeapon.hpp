/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 22:30:53 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:02:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <string>

class AWeapon
{
	protected:
		AWeapon(void);
		std::string _name;
		int			_damage;
		int			_ap;
	
	public:
		/* Coplien's form */
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual ~AWeapon(void);

		AWeapon & operator = (AWeapon const & rhs);

		/* Accessor */
		std::string getName(void) const;
		int			getAPCost(void) const;
		int			getDamage(void) const;

		/* Method */
		virtual void attack(void) const = 0;
};

#endif
