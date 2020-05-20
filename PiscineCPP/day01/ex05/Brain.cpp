/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 05:35:12 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 05:35:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::stringstream ss;

	ss << this;
	this->_address = ss.str();
	std::cout << "Brain's constructor called!" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain's Destructor called!" << std::endl;
}

std::string Brain::identify(void) {
	for (int i = 2; i < this->_address.length(); i++) {
		this->_address[i] = toupper(this->_address[i]);
	}
	return(this->_address);
}
