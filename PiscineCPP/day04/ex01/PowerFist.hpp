/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:17:34 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:17:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"
# include <iostream>

class PowerFist : public AWeapon
{
	public:
		/* Coplien's form */
		PowerFist(void);
		PowerFist(PowerFist const & src);
		~PowerFist(void);
		PowerFist & operator = (PowerFist const & rhs);
		/* method */
		virtual void attack(void) const;
};

#endif
