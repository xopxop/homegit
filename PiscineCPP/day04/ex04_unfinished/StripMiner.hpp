/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:13:09 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 02:13:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIP_MINER_HPP
# define TRIP_MINER_HPP
# include <iostream>
# include "IMiningLaser.hpp"

class StripMiner : public IMiningLaser
{
	public:
		StripMiner(void);
		StripMiner(const StripMiner & src);
		StripMiner & operator=(const StripMiner & rhs);
		~StripMiner(void);

		void mine(IAsteroid*);	
};

#endif
