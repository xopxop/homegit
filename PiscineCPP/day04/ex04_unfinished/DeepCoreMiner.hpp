/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:05:22 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 02:11:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEP_CORE_MINER_HPP
# define DEEP_CORE_MINER_HPP
# include <iostream>
# include "IMiningLaser.hpp"

class DeepCoreMiner : public IMiningLaser
{
	public:
		DeepCoreMiner(void);
		DeepCoreMiner(const DeepCoreMiner & src);
		DeepCoreMiner & operator=(const DeepCoreMiner & rhs);
		~DeepCoreMiner(void);

		void mine(IAsteroid*);	
};

#endif
