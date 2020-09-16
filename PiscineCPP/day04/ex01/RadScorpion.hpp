/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 23:53:37 by dthan             #+#    #+#             */
/*   Updated: 2020/08/31 03:34:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP
# include "Enemy.hpp"
# include <iostream>

class RadScorpion : public Enemy
{
	public:
		/* Coplien's form */
		RadScorpion(void);
		RadScorpion(RadScorpion const & src);
		~RadScorpion(void);
		RadScorpion & operator = (RadScorpion const & src);
};

#endif
