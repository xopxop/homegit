/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:23:11 by dthan             #+#    #+#             */
/*   Updated: 2020/04/22 14:23:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) : foo(0) {

	std::cout << "Constructor called" << std::endl;
	return;

}

Sample::~Sample(void) {

	std::cout << "Destructor called" << std::endl;
	return;

}

void Sample::bar(void) const {
	
	std::cout << "Member function bar called" << std::endl;
	return;
	
}
