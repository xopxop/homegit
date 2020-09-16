/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:41:19 by dthan             #+#    #+#             */
/*   Updated: 2020/08/30 23:52:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP
# include "Enemy.hpp"
# include <iostream>

class SuperMutant : public Enemy
{
	public:
		/* Coplien's form */
		SuperMutant(void);
		SuperMutant(SuperMutant const & src);
		~SuperMutant(void);
		SuperMutant & operator = (SuperMutant const & src);

		virtual void takeDamage(int damage);
};

#endif
