/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:08:30 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 02:14:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void) { }

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner & src)
{
	*this = src;
}

DeepCoreMiner & DeepCoreMiner::operator=(const DeepCoreMiner & rhs)
{
	return *this;
}

DeepCoreMiner::~DeepCoreMiner(void) { }

void DeepCoreMiner::mine(IAsteroid *result)
{
	std::cout << "* mining deep ... got " << result->beMined() << " ! *" << std::endl;
}
