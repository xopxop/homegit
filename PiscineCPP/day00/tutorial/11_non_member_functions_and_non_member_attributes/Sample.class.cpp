/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:04:56 by dthan             #+#    #+#             */
/*   Updated: 2020/04/22 14:04:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;

	return;
}

Sample::~Sample(void) {
	
	std::cout << "Destructor called" << std::endl;
	Sample::_nbInst -= 1;

	return;
}

int	Sample::getNbInst(void) {

	return Sample::_nbInst;
}

int Sample::_nbInst = 0;
