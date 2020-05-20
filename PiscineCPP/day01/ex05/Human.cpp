/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 05:35:25 by dthan             #+#    #+#             */
/*   Updated: 2020/05/10 05:35:25 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) {
	std::cout << "Human's Constructor called!" << std::endl;
}

Human::~Human(void) {
	std::cout << "Human's Destructor called!" << std::endl;
}

std::string Human::identify(void) {
	return (this->brain.identify());
}

Brain& Human::getBrain(void) {
	return (this->brain);
}
