/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 22:50:51 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:17:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"
# include <iostream>

class PlasmaRifle : public AWeapon
{
	public:
		/* Coplien's form */
		PlasmaRifle(void);
		PlasmaRifle(PlasmaRifle const & src);
		~PlasmaRifle(void);
		
		PlasmaRifle & operator = (PlasmaRifle const & rhs);
		/* method */
		virtual void attack(void) const;
};

#endif
