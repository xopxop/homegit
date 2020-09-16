/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:14:02 by dthan             #+#    #+#             */
/*   Updated: 2020/09/01 02:16:42 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner(void) { }

StripMiner::StripMiner(const StripMiner & src)
{
	*this = src;
}

StripMiner & StripMiner::operator=(const StripMiner & rhs)
{
	return *this;
}

StripMiner::~StripMiner(void) { }

void StripMiner::mine(IAsteroid *result)
{
	std::cout << "* mining deep ... got " << result->beMined() << " ! *" << std::endl;
}
